from . import db
from datetime import datetime

# 会员数据模型
class User(db.Model):
    __tablename__ = "user"
    __table_args__ = {"useexisting": True}
    id = db.Column(db.Integer, primary_key=True)  # 编号
    username = db.Column(db.String(100)) # 用户名
    pwd = db.Column(db.String(100))  # 密码
    email = db.Column(db.String(100), unique=True)  # 邮箱
    phone = db.Column(db.String(11), unique=True)  # 手机号
    info = db.Column(db.Text)  # 个性简介
    face = db.Column(db.String(255), unique=True)  # 头像
    addtime = db.Column(db.DateTime, index=True, default=datetime.now)  # 注册时间
    userlogs = db.relationship('Userlog', backref='user')  # 会员日志外键关系关联
    collect = db.relationship('Collect', backref='user')  # 收藏外键关系关联
    
    def __repr__(self):
        return '<User %r>' % self.name

    def check_pwd(self, pwd):
        """
        检测密码是否正确
        :param pwd: 密码
        :return: 返回布尔值
        """
        from werkzeug.security import check_password_hash
        return check_password_hash(self.pwd, pwd)

# 管理员
class Admin(db.Model):
    __tablename__ = "admin"
    __table_args__ = {"useexisting": True}
    id = db.Column(db.Integer, primary_key=True)  # 编号
    name = db.Column(db.String(100), unique=True)  # 管理员账号
    pwd = db.Column(db.String(100))  # 管理员密码
    adminlogs = db.relationship("Adminlog", backref='admin')  # 管理员登录日志外键关系关联
    oplogs = db.relationship("Oplog", backref='admin')  # 管理员操作日志外键关系关联

    def __repr__(self):
        return "<Admin %r>" % self.name

    def check_pwd(self, pwd):
        """
        检测密码是否正确
        :param pwd: 密码
        :return: 返回布尔值
        """
        from werkzeug.security import check_password_hash
        return check_password_hash(self.pwd, pwd)


# 管理员登录日志
class Adminlog(db.Model):
    __tablename__ = "adminlog"
    __table_args__ = {"useexisting": True}
    id = db.Column(db.Integer, primary_key=True)  # 编号
    admin_id = db.Column(db.Integer, db.ForeignKey('admin.id'))  # 所属管理员
    ip = db.Column(db.String(100))  # 登录IP
    addtime = db.Column(db.DateTime, index=True, default=datetime.now)  # 登录时间

    def __repr__(self):
        return "<Adminlog %r>" % self.id


# 操作日志
class Oplog(db.Model):
    __tablename__ = "oplog"
    __table_args__ = {"useexisting": True}
    id = db.Column(db.Integer, primary_key=True)  # 编号
    admin_id = db.Column(db.Integer, db.ForeignKey('admin.id'))  # 所属管理员
    ip = db.Column(db.String(100))  # 操作IP
    reason = db.Column(db.String(600))  # 操作原因
    addtime = db.Column(db.DateTime, index=True, default=datetime.now)  # 登录时间

    def __repr__(self):
        return "<Oplog %r>" % self.id

# 地区
class Area(db.Model):
    __tablename__ = "area"
    id = db.Column(db.Integer, primary_key=True)  # 编号
    name = db.Column(db.String(100), unique=True)  # 标题
    addtime = db.Column(db.DateTime, index=True, default=datetime.now)  # 添加景区时间
    is_recommended = db.Column(db.Boolean(), default=0) # 是否推荐
    introduction = db.Column(db.Text)           # 景区简介
    scenic = db.relationship("Scenic", backref='area')  # 外键关系关联

    def __repr__(self):
        return "<Area %r>" % self.name

# 会员登录日志
class Userlog(db.Model):
    __tablename__ = "userlog"
    __table_args__ = {"useexisting": True}
    id = db.Column(db.Integer, primary_key=True)  # 编号
    # 设置外键
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'))  # 所属会员
    ip = db.Column(db.String(100))  # ip地址
    addtime = db.Column(db.DateTime, index=True, default=datetime.now)  # 登录时间

    def __repr__(self):
        return '<User %r>' % self.id


# 景区
class Scenic(db.Model):
    __tablename__ = "scenic"
    id = db.Column(db.Integer, primary_key=True)  # 编号
    title = db.Column(db.String(255), unique=True)  # 标题
    star  = db.Column(db.Integer)  # 星级
    logo = db.Column(db.String(255), unique=True)  # 封面
    introduction = db.Column(db.Text)           # 景区简介
    content = db.Column(db.Text)           # 景区内容描述
    address = db.Column(db.Text) # 景区地址
    is_hot  = db.Column(db.Boolean(), default=0) # 是否热门
    is_recommended = db.Column(db.Boolean(), default=0) # 是否推荐

    # 设置外键
    area_id = db.Column(db.Integer, db.ForeignKey('area.id'))  # 所属标签
    addtime = db.Column(db.DateTime, index=True, default=datetime.now)  # 添加时间
    collect = db.relationship("Collect", backref='scenic')  # 收藏外键关系关联
    travels = db.relationship("Travels", backref='scenic')  # 游记外键关系关联

    def __repr__(self):
        return "<Scenic %r>" % self.title

# 游记
class Travels(db.Model):
    __tablename__ = "travels"
    id = db.Column(db.Integer, primary_key=True)  # 编号
    title = db.Column(db.String(255),unique=True) # 标题
    author = db.Column(db.String(255))      # 作者
    content = db.Column(db.Text)           # 游记内容
    scenic_id = db.Column(db.Integer, db.ForeignKey('scenic.id'))  # 所属景区
    addtime = db.Column(db.DateTime, index=True, default=datetime.now)  # 添加时间


# 景区收藏
class Collect(db.Model):
    __tablename__ = "collect"
    __table_args__ = {"useexisting": True}
    id = db.Column(db.Integer, primary_key=True)  # 编号

    scenic_id = db.Column(db.Integer, db.ForeignKey('scenic.id'))  # 所属景区
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'))  # 所属用户
    addtime = db.Column(db.DateTime, index=True, default=datetime.now)  # 添加时间

    def __repr__(self):
        return "<Collect %r>" % self.id

# 意见建议
class Suggestion(db.Model):
    __tablename__ = "suggestion"
    __table_args__ = {"useexisting": True}
    id = db.Column(db.Integer, primary_key=True)  # 编号
    name = db.Column(db.String(255))  # 昵称
    email = db.Column(db.String(100))  # 邮箱
    content = db.Column(db.Text)       # 意见内容
    addtime = db.Column(db.DateTime, index=True, default=datetime.now)  # 注册时间

    def __repr__(self):
        return "<Suggestion %r>" % self.id