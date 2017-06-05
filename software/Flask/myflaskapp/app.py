from flask import Flask, g, render_template, request, redirect

import sqlite3
app = Flask(__name__)

DATABASE = 'app.db'
FIRST_RUN = 'create table notes(id integer primary key \
            autoincrement, title text, note text)'

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


@app.route('/')
def hello_world():
  data = query_db('select * from notes')
  result=""
  for note in data:
    result+=note[1] + "   " + note[2] + "<br>"
  return result

@app.route('/init')
def init_db():
    with app.app_context():
        db = get_db()
        db.cursor().execute(FIRST_RUN)
        db.commit()
    return 'Initialised'

@app.route('/note/add', methods=['POST','GET'])
def add_note():
  if request.method=='POST':
    sql = 'insert into notes(title,note) \
    values("%s","%s")' % (request.form["title"],request.form["note"])
    execute_db(sql)
    return 'Note Added'
  else:
    return render_template('form.html')  
  
if __name__=="__main__":
  app.run(host='0.0.0.0',port=3000, debug=True)