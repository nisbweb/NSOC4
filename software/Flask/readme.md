
# Hello World App
```python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)
```

# Routing (Links)
```python
@app.route('/')
def index():
    return 'Index Page'

@app.route('/hello')
def hello():
    return 'Hello, World'
```

# Variable in Links
```python
@app.route('/user/<username>')
def show_user_profile(username):
    # show the user profile for that user
    return 'User %s' % username
```

# URL Building
```python
with app.test_request_context():
    print url_for('index')
    print url_for('login')
    print url_for('login', next='/')
    print url_for('profile', username='John Doe')
```

# URL Building (Static Files)
```python
url_for('static', filename='style.css')
```

# Request Methods
```python
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        if 'email' in request.args and 'pass' in request.args:
            do_the_login(request.form["email"], request.form["pass"])
    else:
        show_the_login_form()
```

# Intro to Templates
```python
from flask import render_template

# Both Routes Lead to hello()
@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name=None):
    return render_template('hello.html', name=name)
```

# Database
```python
from flask import Flask, g, render_template, request, redirect
import sqlite3
app = Flask(__name__)

DATABASE = 'app.db'
FIRST_RUN = 'first.sql'


def get_db():
    db = getattr(g, '_database', None)
    if db is None:
        db = g._database = sqlite3.connect(DATABASE)
    return db

@app.teardown_appcontext
def close_connection(exception):
    db = getattr(g, '_database', None)
    if db is not None:
        db.close()

def init_db():
    with app.app_context():
        db = get_db()
        with app.open_resource(FIRST_RUN, mode='r') as f:
            db.cursor().execute(f.read())
        db.commit()

def query_db(query, args=(), one=False):
    cur = get_db().execute(query, args)
    rv = cur.fetchall()
    cur.close()
    return (rv[0] if rv else None) if one else rv

def execute_db(query):
    cur = get_db()
    cur.execute(query)
    cur.commit()
    cur.close()

@app.route('/init')
def init_route():
    init_db()
    return 'DB Initialised'

@app.route('/')
def index():
    return render_template('view.html',data = query_db('select * from notes'))

@app.route('/addnote', methods=['POST', 'GET'])
def add_note():
    if request.method == 'POST':
        sql = 'insert into notes(title,note) \
        values("'+ request.form['title'] +'","'+ request.form['note'] +'")'
        execute_db(sql)
        return redirect('/')
    else:
        return render_template('addnote.html')

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)

```
