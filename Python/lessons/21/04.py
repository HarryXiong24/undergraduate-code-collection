from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return render_template('index.html')

@app.route('/user/<username>')
def show_user_profile(username):
    # 显示该用户名的用户信息
    return render_template('user.html', name=name)

if __name__ == '__main__':
    app.run(debug=True)