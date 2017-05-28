from flask import Flask, url_for
app = Flask(__name__)


@app.route('/')
def hello_world():
    return 'Hey goto  <a href="' + url_for('page2',username="mridul") + '"> Page 2</a><br>' + \
    '<a href="'+ url_for('page1') +'">Page One</a>'


@app.route('/path/to/page1')
def page1():
    return 'Page 1'

@app.route('/redirector')
def redi():
    return redirect(url_for('page1'))


@app.route('/very/long/<username>/page2')
def page2(username):
    return 'I am Page 2 ' + username + \
    '<br><img src="'+ url_for('static',filename = 'profile.png') +'">'


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)
