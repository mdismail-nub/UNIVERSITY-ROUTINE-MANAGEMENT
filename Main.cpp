#include <bits/stdc++.h>
using namespace std;

struct course{
    int id;
    string coursecode;
    string coursename;
    float credit;
};

void studentmenu(){
    cout<<"========== STUDENT PORTAL ========== \n Student portal is under development. \n 1. Back";
}
void showcourse(course courses){
    cout << "ID: " << courses.id << endl;
    cout << "Code: " << courses.coursecode << endl;
    cout << "Name: " << courses.coursename << endl;
    cout << "Credit: " << courses.credit << endl;
}
void updatecourse(course courses[], int coursecount)
{
    if(coursecount == 0){
        cout << "There is no course!!" << endl;
        return;
    }
    cout << "Enter Course ID to update: ";
    int id;
    cin >> id;
    int upid = -1;
    for(int i = 0; i < coursecount; i++){
        if(courses[i].id == id){
            upid = i;
            break;
        }
    }

    if(upid == -1){
        cout << "Course not found!" << endl;
        return;
    }
    cout << "Enter New Course Code: ";
    cin >> courses[upid].coursecode;

    cin.ignore();

    cout << "Enter New Course Name: ";
    getline(cin, courses[upid].coursename);

    cout << "Enter New Credit: ";
    cin >> courses[upid].credit;

    cout << "Course updated successfully!" << endl;
}

void addcourse(course courses[], int &coursecount){
    if(coursecount>=5){
        cout << "Course limit reached! Cannot add more courses." << endl;
        return;
    }
    cout << "Enter Course ID: ";
    cin >> courses[coursecount].id;

    cout << "Enter Course Code: ";
    cin >> courses[coursecount].coursecode;

    cin.ignore(); 

    cout << "Enter Course Name: ";
    getline(cin, courses[coursecount].coursename);

    cout << "Enter Credit: ";
    cin >> courses[coursecount].credit;
    
    coursecount++;
}
void viewcourses(course courses[], int coursecount){
    for(int i=0;i<coursecount;i++){
        showcourse(courses[i]);
    }
}

void coursemanagement (course courses[] ,int size,int &coursecount){
    while(true){
    cout<<"========== COURSE MANAGEMENT ==========\n\n1. Add Course\n2. View Courses\n3.Update Courses\n4. Back"<<endl;
    int choice;
    cout<<"Enter Your Choice";
    cin>>choice;
    switch (choice){
        case 1:
        addcourse(courses,coursecount);
        break;
        case 2:
        viewcourses(courses,coursecount);
        break;
        case 3:
        updatecourse(courses,coursecount);
        break;
        case 4:
        return;
        default:
        cout<<"Invalid choice!"<<endl;
    }
    }

}

void adminmenu(course courses[] , int size,int &coursecount){
    cout<<"========== ADMIN PORTAL ==========\n Admin portal is under development."<<endl;
    cout<<"1.coursemanagement"<<endl;
    cout<<"2. Back"<<endl;
    int choice;
    cout << "Enter your choice: ";
    cin>>choice;
    
    switch(choice){
        case 1:
        coursemanagement(courses,size,coursecount);
        break;
        case 2:
        return;
        default:
        cout<<"Invalid Choice"<<endl;
    }
    
    
}




int main() {
	// your code goes here
	
	course courses[5];
	
	int coursecount = 0;
	
/*	for(int i=0;i<5;i++){
	    cout<<"\n========== COURSE"<<i+1<<"=========="<<endl;
        showcourse(courses[i]);
} */
	while(true){
	cout<<"========================================"<<endl;
	cout<<"UNIVERSITY ROUTINE MANAGEMENT"<<endl;
	cout<<"========================================"<<endl;
	
	cout<<"1.Student Portal \n 2. Admin Portal \n 3. Exit"<<endl;
	cout<<"Enter Your Choice: ";
	int Choice;
	cin>>Choice;
	
	switch(Choice){
	    case 1:
	    studentmenu();
	    break;
	    case 2:
	    adminmenu(courses,5,coursecount);
	    break;
	    case 3:
	    cout<<"Thank you for using the system!"<<endl;
	     return 0;
	    default:
	    cout<<"Choose a valid option"<<endl;
	    break;
	}
	
	}
    
}
