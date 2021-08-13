from flask import Flask , render_template
from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField,SubmitField
from wtforms.validators import Required

class LoginForm(FlaskForm):
    name = StringField(label='用户名', validators=[Required("用户名不能为空")])
    password = PasswordField(label='密码', validators=[Required("密码不能为空")])
    submit = SubmitField(label="提交")

app = Flask(__name__)
app.config['SECRET_KEY'] = 'mrsoft'

@app.route('/', methods=['GET', 'POST'])
def index():
    form = LoginForm()
    data = {}
    if form.validate_on_submit():
        data['name'] = form.name.data
        data['password'] = form.password.data
    return render_template('index.html', form=form,data=data)

if __name__ == '__main__':
        app.run(debug=True)    