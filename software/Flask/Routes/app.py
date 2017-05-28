from flask import Flask
app = Flask(__name__)


@app.route('/')
def hello_world(num=1):
    return 'Hello World'


# Multi route and Vars from URL
@app.route('/<fullname>/name')
@app.route('/name/<fullname>')
def print_name(fullname):
    return 'Hello ' + fullname


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)
