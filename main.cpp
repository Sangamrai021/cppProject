#include<iostream>
#include<string>
#include<vector>
using namespace std;
class User{
	private:
		string username, password;
	public:
		User(string name, string pass)
		{
			username = name;
			password =pass;
		}
		string getUsername()
		{
			return username;
		}
		string getPassword()
		{
			return password;
		}
};
class UserManager{
	private:
		vector<User> users;  //create object of vector
	public:
		void RegisterUser()
		{
			string username, password;
			cout<<"\n\t\tEnter User Name : ";
			cin>>username;
			cout<<"\t\tEnter Password : ";
			cin>>password;
			
			User newUser(username,password);
			users.push_back(newUser);
			
			cout<<"\n\t\t User Registered Sucessfully ................"<<endl;
		}
		//creating a method for login
		bool LoginUser(string name, string pass)
		{
			for(int i=0; i<users.size();i++)
			{
				if(users[i].getUsername()==name && users[i].getPassword() == pass)
				{
					cout<<"\n\t\t Login Sucessfully.........."<<endl;
					return true;
				}
				}	
				cout<<"\t\t Invalid User Name or Password..."<<endl;
				return false;
		}
};
main()
{
	UserManager usermanage;
	
	int op;
	char choice;
	do{
		system("cls");
		cout<<"\n\t\tWelcome To Registration & Login Form" <<endl;
		cout<<"\t\t************************************" <<endl;
		cout<<"\n\n\t\t1. Register User" <<endl;
		cout<<"\t\t2. Login "<<endl;
		cout<<"\t\t3. Show User List" <<endl;
		cout<<"\t\t4. Search User " <<endl;
		cout<<"\t\t5. Delete User "<<endl;
		cout<<"\t\t6. Exit " <<endl;
		cout<<"\n\n\t\tEnter Your Choice : ";
		cin>>op;
		
		switch(op)
		{
			case 1:
			{
				usermanage.RegisterUser();
				break;
			}
			case 2:
			{
				string username,password;
				cout<<"\n\t\t Enter Username : ";
				cin>>username;
				cout<<"\t\t Enter Password : ";
				cin>>password;
				usermanage.LoginUser(username, password);
				break;
			}
				
		}
		cout<<"\nDo You Want to Continue [Yes/No] :  ";
		cin>>choice;
		
	}while(choice == 'y' || choice == 'Y');

}