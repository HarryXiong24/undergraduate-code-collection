from flask import Flask , url_for
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello World!'

@app.route('/user/<username>')
def show_user_profile(username):
    # 显示该用户名的用户信息
    return 'User %s' % username

@app.route('/post/<int:post_id>')
def show_post(post_id):
    # 根据ID显示文章，ID是整型数据
    return 'Post %d' % post_id

@app.route('/url/')
def get_url():
    # 根据ID显示文章，ID是整型数据
    return url_for('show_post',post_id=2)

if __name__ == '__main__':
    app.run(debug=True)