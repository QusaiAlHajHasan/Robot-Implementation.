/*
Name        : Qussai Al-Hajj Hasan.
ID          : 20160171050.
Section     : 3.
Description : Robot Implementation.
*/

#include <iostream> 
#include <algorithm>
#include <cmath>
using namespace std;
struct  Robot
{
  //declare public variables
  int ID;
  int x, y;  
};

class list
{
  //declare privet variable & pointer
  int length, maxSize;
  Robot * Rlist;

public:
  //public function protoType
  list(int =100);
  void insert (Robot &);
  void sort();
  int  search (int);
  int  search (int, int);
  bool isFull();
  bool isEmpty ();
  void del (int);
  void del (int, int);
  void print (int);
  void print();
};

//implement isEmpty function
bool list ::  isEmpty () {return ( length == 0); }

//implement isFull function
bool list :: isFull() {return (length == maxSize); }

//implement list function
list :: list (int max )
{
  if (max<=0)
    {
      maxSize = 100;
     }
   length = 0;
   Rlist =new Robot[maxSize];
}

//implement insert function
void list :: insert (Robot & r)
{
  if(!isFull())
    {
      if(search(r.ID) == -1)
	{
	  Rlist[length].x= r.x;
	  Rlist[length].y= r.y;
	  Rlist[length].ID= r.ID;
	  length++;
	  sort();
	}
      else
	cout<<"This ID already exist"<<endl;
    }

  else
    cout<<"Sorry, The list is FULL"<<endl;
}

//implement sort function
void list :: sort()
{
  for(int i=0; i<length; i++)
    {
      for(int j=0; j<length; j++)
	{
	  if(Rlist[j].ID<Rlist[i].ID)
	    swap(Rlist[j],Rlist[i]);
	}
    }
}

//implement search id function
int list :: search (int id)
{
  for(int i=0; i<length; i++)
    {
      if(id == Rlist[i].ID)
	return i;
    }
  return -1;
}

//implement searc coordinates function
int list :: search (int a, int b)
{
  for(int i=0; i<length; i++)
    {
      if(a == Rlist[i].x && b == Rlist[i].y)
	return i;
    }
  return -1;
}

//implement delete function by id
void list :: del (int id)
{
  if(!isEmpty())
    {
      if(search(id) != -1)
	{
	  for(int i = search(id); i< length; i++)
	    {
	      Rlist[i] = Rlist[i+1];
	    }
	  length--;
	}
      else
	cout<<"This element dose not exist"<<endl;
    }
  else
    cout<<"Sorry, the list is EMPTY"<<endl;
}

//implement delete function by coordinates
void list :: del (int a, int b)
{
   if(!isEmpty())
    {
      if(search(a,b) == -1)
	cout<<"This element dose not exist"<<endl;
      else
	{
	  while(search(a,b) != -1)
	    {
	      for(int i = search(a,b); i< length; i++)
		{
		  Rlist[i] = Rlist[i+1];
		}
	      length--;
	    }
	}
    }
  else
    cout<<"Sorry, the list is EMPTY"<<endl;
 
}

//implement print all function
void list :: print ()
{
   cout<<endl<<endl;
  for(int i=0; i<length; i++)
    {
      cout<<"Robot ID : "<<Rlist[i].ID<<" and it\'s coordinate : ("<<Rlist[i].x<<","<<Rlist[i].y<<")"<<endl;
    }
   cout<<endl<<endl;
}

//implement print one item by id
void list :: print (int id)
{
   cout<<endl<<endl;
  int pos = search(id);
  double res;
  for(int i=0; i<length; i++)
    {
      if(i != pos)
	{
	  res = sqrt(pow(Rlist[pos].x-Rlist[i].x,2)+pow(Rlist[pos].y-Rlist[i].y,2));
	  cout<<"The Distance between Robot "<<Rlist[pos].ID<<" and Robot "<<Rlist[i].ID<<" is "<<res<<endl; 
	}
     
    }
   cout<<endl<<endl;
}
int main ()
{
  list t1;
  Robot r1;
  int id, x, y;
  for(int i = 0; i<5; i++)
    {
      cout<<"Enter the Robot info:"<<endl;
      cout<<"---------------------"<<endl;
      cout<<"ID: "; cin>>r1.ID;
      cout<<"X-coordinate: "; cin>>r1.x;
      cout<<"Y-coordinate: "; cin>>r1.y;
      cout<<endl;
      t1.insert(r1);
      cout<<endl<<endl;
    }
  cout<<"Enter Robot id to be deleted: "; cin>>id;
  t1.del(id);
   cout<<endl<<endl;
  cout<<"Enter Robot coordinate to be deleted: "; cin>>x>>y;
  t1.del(x,y);

  cout<<"Enter Robot id to print distance: "; cin>>id;
  t1.print(id);

  t1.print();
  
  return 0;
}
