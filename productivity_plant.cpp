#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h>
//#include <chrono>
using namespace std;
int score = 0;
//using namespace std::chrono;
void
showstarting ()
{
cout << endl;

cout << " W W EEEEE L CCCCC O O O M M EEEEE" << endl;
cout << " W W E L C O O MM MM E " << endl;
cout << " W W W EEEE L C O O M M M M EEEE " << endl;
cout << " W W W W E L C O O M M M E " << endl;
cout << " W W W W E L C O O M M E " << endl;
cout << " W W EEEEE LLLLL CCCCC O O O M M EEEEE" <<
endl; cout << endl;
cout << endl;
cout << " TO" << endl;
cout << endl;
cout << endl;
cout << " PPPP RRRR OOO DD D U U CCCCC TTTTT IIIIII V V IIIIII TTTTT Y Y "
<< endl;
cout << " P P R R O O D D U U C T I V V I T Y Y " << endl;
cout << " PPPP RRRR O O D D U U C T I V V I T Y " << endl;
cout << " P R R O O D D U U C T I V V I T Y " << endl;
cout << " P R R OOO DD D UUUU CCCCC T IIIIII V IIIIII T Y " << endl;
cout<<endl;
cout << endl;
cout << endl;
cout << " PPPP L A N N TTTTT " << endl;
cout << " P P L A A N N N T " << endl;
cout << " PPPP L AAAAA N N N T " << endl;
cout << " P L A A N N N T " << endl;
cout << " P LLLLL A A N N T " << endl;
cout << endl;
}
int
acreate (string & a,string u)
{
string pass, password;
re:
cout << endl << "Create password : ";
cin >> pass;
if(pass.size()<8)
{
cout<<"Password is weak. Strength should be minimum 8 characters."<<endl; goto re;
}
if(pass==u)
{
cout << "Username and password can't be same . For security purpose. Please try different password."<<endl;goto re;
}

cout << endl << "Re-enter to confirm password : ";
cin >> password;
if (pass == password)
{
cout << "Account successfully created" << endl;
a = password;
return 0;
}
else
{
cout << "Password does not match !!!! \n " << endl;
goto re;
}
return 1;
}
int
login (string u, string p, int i)
{
string username, password;
for (; i > 0;)
{
cout << "Enter Username : ";
cin >> username;
cout << "Enter password : ";
cin >> password;
if (username != u || password != p)
{
cout << "Username\\Password Incorrect !!!!\n " << i -
1 << " Attempt Left !!" << endl;
if (i == 1)
{
return 0;
}
login (u, p, --i);
}
if (username == u && password == p)
{
return 1;
}
return 1;
}
return 2;
}
class Task
{

private:
string name;
bool completed;
public:
Task (string n):name (n), completed (false)
{
}
string getName ()const
{
return name;
}
bool isCompleted () const
{
return completed;
}
void markCompleted ()
{
completed = true;
}
};
class ToDoList
{
private:
vector < Task > tasks;
public:
void addTask (const Task & task)
{
cout << "add task in one word" << endl;
tasks.push_back (task);
score++;
}
//to save tasks in file
void savestasktofile (const string & filename)
{
ofstream outfile (filename);
if (outfile.is_open ())
{
for (const auto & task:tasks)
{
outfile << task.getName () << " " <<
(task. isCompleted ()? "completed"
: "pending") <<
endl;
}
cout << "Tasks saved to file." << endl;

outfile.close ();
}
else
{
cerr << "Unable to open file for saving tasks." <<
endl; }
}
void loadtaskfromfile (const string & filename)
{
ifstream infile (filename);
if (infile.is_open ())
{
string taskline;
while (getline (infile, taskline))
{
// Split the line into task name and completion status
stringstream ss (taskline);
string taskname;
string completion_status;
ss >> taskname >> completion_status;
// Determine completion status
bool completed = (completion_status == "completed");
// Create a new Task object with the loaded name and completion status
Task task (taskname);
if (completed)
{
task.markCompleted (); // Mark the task as completed if loaded completion status is true
}
// Add the task to the list
tasks.push_back (task);
}
infile.close ();
cout << "Tasks loaded from file" << endl;
}
else
{
cerr << "Unable to open file for loading tasks." << endl;
}
}
void displayTasks () const
{
if (tasks.empty ())
{
cout << "No tasks in the list!" << endl;
return;

}
cout << "To-Do List:" << endl;
for (const auto & task:tasks)
{
cout << "- " << task.getName () << " ";
if (task.isCompleted ())
cout << "[completed]" << endl;
else
cout << "[pending]" << endl;
}
}
void markTaskCompleted (int index)
{
if (index >= 0 && index < tasks.size ())
{
tasks[index].markCompleted ();
score++;
cout << "Task marked as completed." << endl;
}
else
{
cout << "Invalid task index!" << endl;
}
}
};
class Achievement
{
private:
int pomodoroCount;
int normalStudyCount;
public:
Achievement ():pomodoroCount (0), normalStudyCount (0)
{
}
void incrementPomodoroCount ()
{
pomodoroCount++;
score++;
}
void incrementNormalStudyCount ()
{
normalStudyCount++;
score++;
}
void displayAchievements () const

{
cout << "Achievements:" << endl;
cout << "- Pomodoro Study Sessions: " << pomodoroCount <<
endl; cout << "- Normal Study Sessions: " << normalStudyCount <<
endl; cout << "- Current score: " << score << endl;
}
// Save achievements to a file
void saveAchievementsToFile (const string & filename)
{
ofstream outfile (filename);
if (outfile.is_open ())
{
outfile << pomodoroCount << endl;
outfile << normalStudyCount << endl;
outfile.close ();
cout << "Achievements saved to file." << endl;
}
else
{
cerr << "Unable to open file for saving achievements." << endl;
}
}
// Load achievements from a file
void loadAchievementsFromFile (const string & filename)
{
ifstream infile (filename);
if (infile.is_open ())
{
string line;
if (getline (infile, line))
{
stringstream (line) >> pomodoroCount;
}
if (getline (infile, line))
{
stringstream (line) >> normalStudyCount;
}
infile.close ();
cout << "Achievements loaded from file." <<
endl; }
else
{
cerr << "Unable to open file for loading achievements." << endl;
}
}

};
class ProductivityPlant
{
private:
ToDoList todoList;
Achievement achievement;
public:
ProductivityPlant ()
{
achievement.loadAchievementsFromFile
("achievements.txt"); todoList.loadtaskfromfile ("tasks.txt");
}
// Function to save score to file
void saveScoreToFile (const string & filename)
{
ofstream outfile (filename);
if (outfile.is_open ())
{
outfile << score << endl;
outfile.close ();
cout << "Score saved to file." << endl;
}
else
{
cerr << "Unable to open file for saving score." <<
endl; }
}
// Function to load score from file
void loadScoreFromFile (const string & filename)
{
ifstream infile (filename);
string line;
if (infile.is_open ())
{
if (infile >> score)
{
stringstream (line) >> score;
}
infile.close ();
cout << "Score loaded from file." << endl;
}
else
{
cerr << "Unable to open file for loading score." <<
endl; }

}
void startPomodoro ()
{
int pomodorotime, pomodorobreak, num_of_p;
cout << "Starting Pomodoro Study Session..." <<
endl; achievement.incrementPomodoroCount ();
cout <<"Enter the duration of each session,break and number of sessions\n"; cin >> pomodorotime >> pomodorobreak >> num_of_p;
int newpomodorotime = pomodorotime / 30;
int newpomodorobreak = pomodorobreak / 5;
int ctr = 1;
while (ctr <= num_of_p)
{
cout << "study session started..." << endl;
sleep (newpomodorotime);
cout << "session " << ctr << " completed, take rest " <<
endl; sleep (newpomodorobreak);
cout << "sessions left: " << num_of_p - ctr << endl;
ctr++;
}
cout << "Pomodoro Study Session completed!" << endl;
}
void startNormalStudy ()
{
cout << "Starting Normal Study Session..." << endl;
achievement.incrementNormalStudyCount ();
cout << "Enter duration of study" << endl;
int duration;
cin >> duration;
cout << "Starting study session" << endl;
//QUOTE
int newduration = duration / 30;
sleep (newduration);
cout << "Normal Study Session completed!" << endl;
}
void displayAchievements ()
{
//achievement.loadAchievementsFromFile("achievements.txt");
achievement.displayAchievements ();
}
void addTaskToList (const string & taskName)
{
Task task (taskName);
todoList.addTask (task);

cout << "Task added to the list." << endl;
}
void displayToDoList ()
{
todoList.displayTasks ();
}
void markTaskCompleted (int index)
{
todoList.markTaskCompleted (index);
}
~ProductivityPlant ()
{
// Save achievements to file when destroying the object
achievement.saveAchievementsToFile
("achievements.txt"); todoList.savestasktofile ("tasks.txt");
}
};
template < typename T, typename S >
class calc
{
public:
S a;
T b;
S ans;
calc ()
{
cout << "WELCOME TO CALCULATOR: \n THIS CALCULATOR IS DESIGNED TO PERFORM\SIMPLE MATHEMATICAL OPERATIONS INCLUDING + - * / %" <<
endl;
}
S add (T & a, T & b)
{
ans = a + b;
return ans;
}
S sub (T & a, T & b)
{
ans = a - b;
return ans;
}
S mul (T & a, T & b)
{
ans = a * b;
return ans;

}
S div (T & a, T & b)
{
ans = a / b;
return ans;
}
S rem (T & a, T & b)
{
ans = a % b;
return ans;
}
};
class bmi
{
public:
double ans;
int userans;
bmi ()
{
cout << "WELCOME TO BMI CALCULATOR" << endl;
cout <<
"---------------------------------------------------------------------------------"
<< endl;
cout << "Body mass index is a value derived from the mass and height of a person. \n The BMI\is defined as the body mass divided by the square of the body height" <<
endl;
cout << "PRESS: \n1 for metric system \n2 for US units " << endl;
cout << "BMI is an estimate of body fat and a good gauge of your risk for diseases that can\occur with more body fat. The higher your BMI, the higher your risk for certain diseases suchas\ heart disease, high blood pressure, type 2 diabetes, gallstones, breathing problems, and certain\ cancers." << endl;
cout <<"---------------------------------------------------------------------------------"<< endl;
cin >> userans;
cout << "YOU CHOSE: " << userans << endl;
}
double metric ()
{
double h, w;
cout << "Enter height (in cm) and weight (kg) " << endl;
cin >> h >> w;
h = h / 100;
ans = w / (h * h);
return ans;
}

double us ()
{
double w, h;
cout << "Enter height (inches) and weight (pounds) " << endl;
cin >> h >> w;
ans = w / (h * h);
return ans;
}
};
void
badges ()
{
int bad;
cout << "You earn 1 badge for every 10 badges earned. " << endl;
bad = score / 10;
cout << "Total no of badges = " << bad << endl;
cout << "Congrats! You have planted " << bad << " trees out in the real world by being productive\ " << endl;
}
void
check (double b)
{
if (b > 25)
{
cout << endl;
cout << "you are: OVERWEIGHT : " << b << endl;
cout << "Risks associated with being overweight" << endl;
cout << "High blood pressure \n Higher levels of LDL cholesterol, which is widely considered\ bad cholesterol, lower levels of HDL cholesterol, considered to be good cholesterol in\ moderation, and high levels of triglycerides \n Type II diabetes \n Coronary heart disease \n\ Stroke \n Gallbladder disease \n As can be seen from the list above, there are numerous\ negative, in some cases fatal, outcomes that may result from being overweight. Generally, a\ person should try to maintain a BMI below 25 kg/m2, but ideally should consult their doctor to\ determine whether or not they need to make any changes to their lifestyle in order to be\ healthier." << endl;
}
else if (b < 19)
{
cout << endl;
cout << "you are : UNDERWEIGHT : " << b << endl;
cout << "Risks associated with being underweight : " << endl;
cout << "Malnutrition, vitamin deficiencies, anemia (lowered ability to carry blood vessels)\\nOsteoporosis, a disease that causes bone weakness, increasing the risk of breaking a\bone\nA decrease in immune function\nGrowth and development issues, particularly inchildren\and teenagers\nPossible reproductive issues for women due to hormonal imbalancesthat can\disrupt the menstrual cycle. Underweight women also have a higher chance of miscarriagein\the first trimester" <<endl;
}
else
cout << "CONGRATS, YOUR BMI IS WITHIN RANGE : " << b << endl;
}
int
main ()
{
showstarting ();
string u_name, password = "null";
cout << "Create Account" << endl;
u:
cout << "Create a Username : ";
cin >> u_name;
if(u_name.size()<8)
{
cout<<"Username should be of more than 8 characters.Please re-enter."<<endl; goto u;
}
ProductivityPlant plant;
Achievement achievement;
int choice, t;
t = acreate (password,u_name);
t = 3;
t = login (u_name, password, t);
if (t == 0)
return 0;
else
{
cout << "You are Successfully Logged In..." << endl << endl << "||||| Welcome toProductivePlant\|||||" << endl <<endl;
achievement.loadAchievementsFromFile
("achievements.txt"); plant.loadScoreFromFile ("score.txt");
do
{
cout << endl;
cout << endl;

cout << "=====================================" <<
endl; cout << " Welcome to Productive Plant" << endl;
cout << "=====================================" <<
endl; cout << "0. Open Simple Calculator ..." << endl;
cout << "1. Start Pomodoro Study Session ..." << endl;
cout << "2. Start Normal Study Session ..." << endl;
cout << "3. View Achievements ..." << endl;
cout << "4. Add Task to To-Do List ..." << endl;
cout << "5. Display To-Do List ..." << endl;
cout << "6. Mark Task as Completed ..." << endl;
cout << "7. Open BMI Calculator ..." << endl;
cout << "8. Quit *" << endl;
cout << "=====================================" <<
endl; cout << "Enter your choice: ";
cin >> choice;
switch (choice)
{
case 0:
{
calc < int, int >cal;
cout <<
"Enter 1 for integer calculator or 2 for float calculator t"
<< endl;
int userans;
int a, b;
double c, d;
char op;
cin >> userans;
if (userans == 1)
{
cout << "Enter two integer numbers" <<
endl; cin >> a >> b;
cout << "Enter the operation you want:" <<
endl; cout << "+ - * / %" << endl;
cin >> op;
if (op == '+')
cout << " = " << cal.add (a, b);
else if (op == '-')
cout << " = " << cal.sub (a, b);
else if (op == '*')
cout << " = " << cal.mul (a, b);
else if (op == '/')
cout << " = " << cal.div (a, b);
else if (op == '%')
cout << " = " << cal.rem (a, b);

}
if (userans == 2)
{
calc < double, double >cal1;
cout << "Enter two float numbers" << endl;
cin >> c >> d;
cout << "Enter the operation you want:" <<
endl; cout << "+ - * / %" << endl;
cin >> op;
if (op == '+')
cout << " = " << cal1.add (c, d);
else if (op == '-')
cout << " = " << cal1.sub (c, d);
else if (op == '*')
cout << " = " << cal1.mul (c, d);
else if (op == '/')
cout << " = " << cal1.div (c, d);
else if (op == '%')
cout << "NOT POSSIBLE" << endl;
}cout << endl;
break;
}case 1:
{
plant.startPomodoro ();
achievement.saveAchievementsToFile
("achievements.txt"); break;
}
case 2:
{
plant.startNormalStudy ();
achievement.saveAchievementsToFile
("achievements.txt"); break;
}
case 3:
{
plant.displayAchievements ();
cout <<
"Press 1 for viewing no of badges else, else, press 0"
<< endl;
int badgeans;
cin >> badgeans;
if (badgeans == 1)
badges ();
else
continue;
break;

}
case 4:
{
string taskName;
cout << "Enter task name: ";
cin.ignore ();
getline (cin, taskName);
plant.addTaskToList (taskName);
break;
}
case 5:
{
plant.displayToDoList ();
break;
}
case 6:
{
int index;
cout << "Enter task index to mark as completed: ";
cin >> index;
plant.markTaskCompleted (index);
break;
}
case 7:
{
try
{
bmi bmiobj;
if (bmiobj.userans == 1)
{
double ans = bmiobj.metric ();
cout << "your BMI is : " << ans <<
endl; check (ans);
}
else if (bmiobj.userans == 2)
{
double ans = bmiobj.us ();
cout << "your BMI is : " << ans <<
endl; check (ans);
}
else
throw "INVALID CHOICE, EXITTING...";
}
catch (const char *s)
{

cout << "Exception caught: " << s <<
endl; }
break;
}
case 8:
{
cout << "Exiting...Goodbye!" << endl;
break;
}
default:
cout << "Invalid choice. Please try again." <<
endl; }
}
while (choice != 8);
plant.saveScoreToFile ("score.txt");
}
return 0;
}
