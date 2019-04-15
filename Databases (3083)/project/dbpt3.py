#Import Flask Library
from flask import Flask, render_template, request, session, url_for, redirect
import pymysql.cursors

#Initialize the app from Flask
app = Flask(__name__)
app.secret_key = 'a super secret key'


#Configure MySQL
conn = pymysql.connect(host='localhost',
                       user='root',
                       password ='erffy',
                       db='project',
                       charset='utf8mb4',
                       cursorclass=pymysql.cursors.DictCursor)


@app.route('/')
def hello():
    return render_template('index.html')


#Define route for login
@app.route('/login')
def login():
	return render_template('login.html')

#Define route for register
@app.route('/register')
def register():
	return render_template('register.html')

#Authenticates the register
@app.route('/registerAuth', methods=['GET', 'POST'])
def registerAuth():
	#grabs information from the forms
	username = request.form['username']
	password = request.form['password']

	#cursor used to send queries
	cursor = conn.cursor()
	#executes query
	query = 'SELECT * FROM user WHERE username = %s'
	cursor.execute(query, (username))
	#stores the results in a variable
	data = cursor.fetchone()
	#use fetchall() if you are expecting more than 1 data row
	error = None
	if(data):
		#If the previous query returns data, then user exists
		error = "This user already exists"
		return render_template('register.html', error = error)
	else:
		ins = 'INSERT INTO user (username, password) VALUES(%s, MD5(%s))'
		cursor.execute(ins, (username, password))
		conn.commit()
		cursor.close()
		return render_template('index.html')


#Authenticates the login
@app.route('/loginAuth', methods=['GET', 'POST'])
def loginAuth():
	#grabs information from the forms
	username = request.form['username']
	password = request.form['password']

	#cursor used to send queries
	cursor = conn.cursor()
	#executes query
	query = 'SELECT * FROM user WHERE username = %s and password = MD5(%s)'
	cursor.execute(query, (username, password))
	#stores the results in a variable
	data = cursor.fetchone()
	#use fetchall() if you are expecting more than 1 data row
	cursor.close()
	error = None
	if(data):
		#creates a session for the the user
		#session is a built in
		session['username'] = username
		return redirect(url_for('home'))
	else:
		#returns an error message to the html page
		error = 'Invalid login or username'
		return render_template('login.html', error=error)






#Define route for adding a friend
@app.route('/addFriend')
def addFriend():
    print "rendering"
    return render_template('addFriend.html')

#Authenticates the addition
@app.route('/addFriendAuth', methods=['GET', 'POST'])
def addFriendAuth():
    #grabs information from the forms
    friendGroup = request.form['friendGroup'] 
    firstname = request.form['firstname']
    lastname = request.form['lastname']

    #cursor used to send queries
    cursor = conn.cursor()
    #getting username of friend to add
    query = 'SELECT username FROM Person WHERE first_name = %s AND last_name = %s'
    cursor.execute(query, (firstname, lastname))
    error = None
    #stores the results in a variable
    data = cursor.fetchall()

    #use fetchall() if you are expecting more than 1 data row
    if len(data) > 1: #len()
        error = "There are multiple users with that name. Please enter a username:"
        friendName = request.form['friendUsername']
        return render_template('addFriend.html', error = error)
        #return redirect(url_for('addFriend.html', error=error))
    else:
        friendName = data[0] #maybe index this

    print friendName
    
    #adding friend to group using username
    query1 = 'SELECT * FROM Member WHERE username = %s AND group_name = %s AND group_creator = %s' #username?
    cursor.execute(query1, (friendName, friendGroup, username))
    data1 = cursor.fetchone()
	
    if(data1):
        #If the previous query returns data, then user exists
        error = "This user already exists in this friend group"
        return render_template('addFriend.html', error = error)
    ins = 'INSERT INTO Member (group_name, username, group_creator) VALUES(%s, %s, %s)'
    cursor.execute(ins, (friendGroup, friendName, username))
    conn.commit()
    cursor.close()
    return render_template('index.html')

	    



if __name__ == "__main__":
    app.run(debug=True)

