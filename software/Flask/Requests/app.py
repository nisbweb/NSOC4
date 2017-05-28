from flask import Flask, request, render_template
app = Flask(__name__)


@app.route('/', methods=['POST', 'GET'])
def hello_world():
    if request.method == 'POST':
        return 'GOT Request ' + request.form['title'] + "<br>" + request.form['desc']
    else:
        return render_template('send.html')


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)
