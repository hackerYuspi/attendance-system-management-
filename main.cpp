#include<bits/stdc++.h>
#include<string>
using namespace std;

class student
{
	string roll_no;
	string name;
	float subject[5];
	float per[5];	
    public:
	friend void add_new_student_details(student s);
	
};

vector<string> sorting()
{
	int i=0;
	vector<string> student;	
	string line;
	ifstream file("STUDENTS.txt");//,ios::out | ios::in);	

	while(getline(file,line))
	{		
		student.push_back(line);
		
		i++;
	}
	sort(student.begin()+1,student.end());
	
	file.close();
	return student;

}

void writing(vector<string> str)
{
	ofstream file("STUDENTS.txt");

	for(int i=0;i<str.size();i++)
		file<<str[i]<<endl;

	file.close();
}

void add_new_student_details(student s)
{		
	ofstream file("STUDENTS.txt",ios_base::app);	
	
	cout<<"Enter roll no :\n";
	cin>>s.roll_no;

	cout<<"Enter name:\n";
	cin>>s.name;

	cout<<"Enter attendace (out of 30) :\n";
	for(int i=0;i<5;i++)
	{
		switch(i)
		{
			case 0: cout<<"OOP : ";
				cin>>s.subject[i];
				s.per[i]=(s.subject[i]/30)*100;
				break;
			case 1: cout<<"DSD : ";
				cin>>s.subject[i];
				s.per[i]=(s.subject[i]/30)*100;
				break;
			case 2: cout<<"SP : ";
				cin>>s.subject[i];
				s.per[i]=(s.subject[i]/30)*100;
				break;
			case 3: cout<<"Maths : ";
				cin>>s.subject[i];
				s.per[i]=(s.subject[i]/30)*100;
				break;
			case 4: cout<<"Economics : ";
				cin>>s.subject[i];
				s.per[i]=(s.subject[i]/30)*100;
				break;
		}
	}

	file<<s.roll_no<<"      "<<s.name<<"        "<<s.subject[0]<<"    "<<setprecision(4)<<s.per[0]<<"        "<<s.subject[1]<<"    "<<setprecision(4)<<s.per[1]<<"        "<<s.subject[2]<<"    "<<setprecision(4)<<s.per[2]<<"        "<<s.subject[3]<<"    "<<setprecision(4)<<s.per[3]<<"        "<<s.subject[4]<<"    "<<setprecision(4)<<s.per[4]<<endl;

	file.close();
}

void search(string roll)
{
	int i=0;
	vector<string> student;	
	string line;
	fstream file("STUDENTS.txt");	

	while(getline(file,line))
	{		
		student.push_back(line);
		
		i++;
	}
	i=1;
	
	while(i<student.size())
	{
		if(student[i].substr(0,9)==roll)
		{
			cout<<student[0]<<endl<<student[i]<<endl;
		}
		i++;
	}
	file.close();
}


void add(string roll)
{
	int i=0,j=0,k=-1;
	vector<string> student;	
	string line;
	fstream file("STUDENTS.txt");	
	bool spacefound= false ;

	while(getline(file,line))
	{		
		student.push_back(line);
		
		i++;
	}
	i=1;
	
	while(i<student.size())
	{
		if(student[i].substr(0,9)==roll)
		{
			int n=student[i].length();

			while(++k<n && student[i][k]==' ');

			while(k<n)
			{
				if(student[i][k]!=' ')
				{
					if( student[i][k]=='?' || student[i][k]==',' && j-1>=0 && student[i][j-1]==' ')
					{
						student[i][j-1]=student[i][k++];
					}
					else 
					{
						student[i][j++]=student[i][k++];
					}
				spacefound=false;
				}
				
				else if(student[i][k++]==' ' )
				{
					 if (!spacefound) 
            				{ 
                				student[i][j++] = ' '; 
                				spacefound = true; 
            				} 
				}
			}
			if (j <= 1) 
        			student[i].erase(student[i].begin() + j, student[i].end()); 
    			else
    			    	student[i].erase(student[i].begin() + j - 1, student[i].end());
			break;
		}
		i++;
	}

	cout<<student[i]<<endl;
	string word[12];

	int x=0,y=0;

	while(student[i][x]!='\0')
	{
		if(student[i][x]!=' ')
		{
			word[y]+=student[i][x];
		}
		else y++;
		x++;			
	}
	
	y=2;
	float value[10];
	while(y!=12)
	{
		stringstream geek(word[y]);
		geek>>value[y-2];
		y++;	
	}

	int choice;
	float data;

	do{
		cout<<"1.OOP\n2.DSD\n3.SP\n4.MATHS\n5.ECO\n";
		cout<<"Enter your choice :\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1: cout<<"Enter attendance :\n";
				cin>>data;
				value[0]+=data;
				value[1]=(value[0]/30)*100;
				break;
			case 2: cout<<"Enter attendance :\n";
				cin>>data;
				value[2]+=data;
				value[3]=(value[2]/30)*100;
				break;
			case 3: cout<<"Enter attendance :\n";
				cin>>data;
				value[4]+=data;
				value[5]=(value[4]/30)*100;
				break;
			case 4: cout<<"Enter attendance :\n";
				cin>>data;
				value[6]+=data;
				value[7]=(value[6]/30)*100;
				break;
			case 5: cout<<"Enter attendance :\n";
				cin>>data;
				value[8]+=data;
				value[9]=(value[8]/30)*100;
				break;
		}
	}while(choice<=5);

	y=0;
	while(y!=10)
	{
		cout<<endl<<value[y]<<endl;
		y++;	
	}
	student[i]=word[0]+"      "+word[1]+"        ";

	y=2;
	int z=0;
	

	while(y!=12)
	{
		ostringstream str1;
		str1<<value[z];
		
		word[y]=str1.str();
		
		cout<<word[y]<<endl;
		
		if((y%2)==0) 	
			student[i]+=word[y]+"        ";
		else student[i]+=word[y]+"    ";
		y++;
		z++;	
	}

	file.close();

	writing(student);

}

int main()
{
	student s1;
	vector<string> str;
	string str1;

	ofstream file("STUDENTS.txt");

	file<<"Roll_no"<<"        "<<"Name"<<"        "<<"OOP"<<"    "<<"%"<<"        "<<"DSD"<<"    "<<"%"<<"        "<<"SP"<<"    "<<"%"<<"        "<<"MATHS"<<"    "<<"%"<<"        "<<"ECO"<<"    "<<"%"<<endl;
	
	int choice;
	string roll;	

	do{
		cout<<"1.Add new student\n2.Add attendance of existing student\n3.Search attendance %\n";
		cout<<"Choose your option : \n";
		cin>>choice;		
		
		switch(choice)
		{
			case 1: add_new_student_details(s1);
				str=sorting();
				writing(str);
				break;
			case 2: cout<<"Enter roll no : \n";
				cin>>roll;
				add(roll);				
				break;
			case 3: cout<<"Enter roll no : \n";
				cin>>roll;
				search(roll);
				break;			
		}	
	}while(choice<4);

	file.close();	
	
	return 0;
}
