#include <iostream>
#include <string>


using namespace std;


class CarParametrs {
public:
string CarType; // car type
string CarNumber; // car number
int CarManufactoringYear; // car manufactoring year
float CarWeight; // car weight
CarParametrs* pNext; //adress of next element at the list


//-----------------------------------------
CarParametrs(string aCarType, string aCarNumber, int aCarManufactoringYear, float aCarweight) :
CarType(aCarType), CarNumber(aCarNumber),  CarManufactoringYear(aCarManufactoringYear), CarWeight(aCarweight),
pNext(NULL)
{ }//constructor
//-------------------------------------------------------------
void CarsQueue() //display list item
{
cout << " Car Type: [" << CarType << "], Car Number: [" << CarNumber << "],"
 << " Car Manufactoring Year: [" << CarManufactoringYear << "] th." <<  " Car Weight: [" << CarWeight << "] ton. ;"<< endl;
}
//-----------------------------------------------------------

};//end of class CarParameters

class CarLinkedList {
private:
CarParametrs * pFirst;//reference to first element in the list
CarParametrs * pLast;//reference to last element in the list
int count =0 ;//queue counter

public:

CarLinkedList() : pFirst(NULL), pLast(NULL)//constructor
{}
~CarLinkedList()//destructor
{
    CarParametrs* pCurrent = pFirst; //start at the beginning of the list
while (pCurrent != NULL) //until the end of the list
{
CarParametrs* pTemp = pCurrent; //remember the list element to be removed
pCurrent = pCurrent->pNext; //move to next list element
delete pTemp; //deletes the previously remembered
}
}

bool isEmpty() //true if list is empty
{
return pFirst == NULL;
}

//-------------------------------------------------------------
void insertLast(string lCarNumber, string lCarType , int lCarManufactoringYear, float lCarWeight)//insert new element at the end of the list

{
    CarParametrs* pNewLink = new CarParametrs(lCarNumber, lCarType, lCarManufactoringYear, lCarWeight); //a new list item (or data structure) is created
           if (isEmpty()) //if the list is empty
          {  pFirst = pLast = pNewLink;//(first & last) --> newLink, if the list is empty, the new element is assigned a start pointer
          pFirst->pNext=NULL;// newlink->next = nothing
           count++;//queue counter +1
           } 
          else{// if some elements of queue already exist
           pLast->pNext = pNewLink; //old last --> newLink
           pNewLink->pNext=NULL;//newLink --> next = nothing
           pLast = pNewLink; //newLink <-- last
           count++;//queue counter +1
}//else end
}//insertion end
   
//-------------------------------------------------------------

void deleteFirst() // remove the first element
{ CarParametrs* pTemp = pFirst; //remember the first element of the list
        if(!isEmpty())//(assuming the list is not empty)
        {
       if (count == 1)//check if only one element in queue
        {
            delete pFirst;// remove existing element
            pLast = pFirst = NULL;// last and first elements = nothing
            count--;//queue counter -1
        }
        else
        {// if more than one element of queue is exist
            pFirst = pFirst->pNext;//first --> old next
            delete pTemp;//deletes the previously remembered
            count--;//queue counter -1
        }  

}
else cout << "This queue is empty ... [info]" << endl;//message if queue is empty


}
//-------------------------------------------------------------
void deleteLast()// remove the last element
{
if (!isEmpty())//(assuming the list is not empty)
{ 
    if (count == 1)//check if only one element in queue
        {
            delete pFirst;//remove existing element
            pLast = pFirst = NULL;// last and first elements = nothing
            count--;//queue counter -1
        }
        else 
        {// if more than one element of queue already exist
            CarParametrs* pCurrent = pFirst; //remember the first element of the list
            CarParametrs* pPrevious = NULL; //  assign new pointer  to nothing
            while (pCurrent->pNext != NULL )// check until the end of the list
            {
                pPrevious= pCurrent;//the previous pointer is assigned to the current one
                pCurrent = pCurrent->pNext;//move to the next element in the list
            }

            delete (pCurrent); //remove last element
            pPrevious->pNext= NULL;//assign removed element as nothing
            pLast = pPrevious; //the last pointer is assigned to the previous one
            count--;//queue counter -1
        }
}
else cout << "This queue is empty ... [info]" << endl;//message if queue is empty

}


//-------------------------------------------------------------
void showList()//displays all list items
{
 CarParametrs* pCurrent = pFirst;//remember the first element of the list
 int i=1;
         if (!isEmpty()) //(assuming the list is not empty)
         {
         cout << "List contents:" << endl;
         while (pCurrent != NULL) //until the end of the list is reached,
         {
         cout << "[" << i << "] >>";
          i++;
          pCurrent->CarsQueue(); //print data
          pCurrent = pCurrent->pNext; //move to the next list item
          cout << endl;
          }
}
else cout << "This queue is empty ... [info]" << endl;//message if queue is empty



}
//------------------------------------------------------------

void insertionSort( )//Allow crossing the bridge for defined number of car by manufacturing year
{
     

  

if (!isEmpty())//(assuming the list is not empty)
 { 

        int i=0;//start value for loop counter
        int number_check;//defined number of car
        cout << "Please, enter the amount of cars you want to allow crossing the bridge: " ;
        cin >> number_check;


     if (number_check<= count)//comparison with the current number of cars in the queue
     { 
       for(i=0; i < number_check; )
       {
      
          if (count == 1) //check if only one element in queue
          {
                deleteFirst();//delete this element
                i++;//counter for loop +1
                
            } 


         else  {  
            
            CarParametrs* pCurrent = pFirst->pNext;//remember first--> next element 
            CarParametrs* pNewLink = pFirst;//remember the first element of the list
            CarParametrs* pPrevious= pFirst;//remember the first element of the list
            CarParametrs* pBeforemin = NULL; //assign to nothing



            while ( pCurrent != NULL)//until the end
            {
                if (pNewLink->CarManufactoringYear > pCurrent->CarManufactoringYear)//check newest car
                {   
                    pNewLink = pCurrent;//assign new newest vehicle
                    pBeforemin= pPrevious;//remember pointer before assign
                    
                }
               
                pPrevious=pCurrent;//the previous pointer is assigned to the current one
                pCurrent=pCurrent->pNext;//move to the next element in the list
               

            }
                if (pBeforemin== NULL)//if newest car is first in the queue
                {
                  deleteFirst();//delete from queue
                   i++;//counter for loop +1
                }
            else if (pBeforemin->pNext == NULL)//if newest car is last in the queue
             {
                deleteLast();//delete from queue
                i++;//counter for loop +1
            } 
            else

            {//in case if newest in middle of queue
                pCurrent = pBeforemin->pNext;//assign newest car to current
                pBeforemin->pNext=pCurrent->pNext;//skips the element to be deleted
                delete (pCurrent);//delete curent car
                i++;//counter for loop +1
                count--;//queue counter -1
              }
         
          }
    
        }
        
     }   else cout << "You can not allow crosing the bridge for " << number_check << " becouse in queue currently " << count << 
     " cars. Try operation again with current amount or wait until a " <<  number_check - count << " cars placed in line" << endl;
     //displays a message if there are less machines in the queue than the user wants to delete
 }
  else cout << "This queue is empty ... [info]" << endl;//message if queue is empty
}
//-------------------------------------------------------------
void deleteMax()//delete maximum number of cars, not exceeding the bridge capacity
{
  CarParametrs * pCurrent = pFirst;  //remember the first element of the list
  float total_capacity = 500;//start bridge capacity

if(!isEmpty())//(assuming the list is not empty)
{
  
     while (!isEmpty()  &&  pCurrent->CarWeight <= total_capacity)// until the (assuming the list is not empty) and weight of current vechicle allowed for bridge current capacity
         {
          total_capacity= total_capacity - pCurrent->CarWeight;//isertion of new capacity = old capacity - current car weight
          pCurrent=pCurrent->pNext;//move to the next element in the list
           deleteFirst();//delete old first


         }
}
else cout << "This queue is empty ... [info]" << endl;//message if queue is empty
}

};// end of class CarLinkedList

//-------------------------------------------------------------
//Menu functions:
void menuContents() {
cout << "Queue control system:----" << endl;
cout << "-------------------------------------" << endl;
cout << "Select the operation you want to perform:" << endl;
cout << "-------------------------------------" << endl;
cout << "[1] Placing the car in a queue: " << endl;
cout << "[2] Allow crossing the bridge for one car: " << endl;
cout << "[3] Allow crossing the bridge for defined number of car by manufacturing year, new cars go first: " << endl;
cout << "[4] Allow the crossing of the bridge for a maximum number of cars, not exceeding the bridge capacity: " << endl;
cout << "[5] Print the information about the content of the queue: " << endl;
cout << "[6] Finish work: " << endl;
}
void Menu(int *keyPass) {
char keyOperation;
menuContents();
do {
keyOperation = getchar();
if ((isdigit(keyOperation) == false) && (keyOperation != '\n')) {
cout << "You must specify a number... [!]" << endl;
cout << "Try again:" << endl;
menuContents();
}
} while (isdigit((unsigned char)keyOperation) == false);
*keyPass = (int)keyOperation - '0';
}//working with Menu functions, end of...

//-------------------------------------------------------------
//data for input, as public...
string xCarType;//type of car
string xCarNumber;//car number
int xCarManufactoringYear;//car manufactorin year
float xCarWeight;//car weight
//-------------------------------------------------------------
//data assignment...
void getCarData() {
cout << "Specify the type of car: MICRO, SEDAN, CUV, HATCHBACK, ROADSTER, PICKUP, VAN, SUPERCAR, CAMPERVAN, CABRIOLET, MINIVAN, TRUCK "  << endl;
cin >> xCarType ;
cout << "Specify the car number: AD9527B " << endl;
cin >> xCarNumber;
cout << "Specify the car manufactoring year started from 1920 : 2003 " << endl;
cin >> xCarManufactoringYear;
cout << "Specify the car weight. No more than 20 tons! : 15 " << endl;
cin >> xCarWeight;
}

//-------------------------------------------------------------

int main()
{

    int keyPass;
    CarLinkedList takeLine; // output the functions of the CarsLinkedList class

     do {
          Menu(&keyPass);
           switch (keyPass) 
           {
             case 1:
               cout << "Operation [1]" << endl;

               getCarData();
               //parameters checking...

               if (xCarManufactoringYear < 1920 )
               {
               cout << "Sorry, you can not place this car in queue. It is too old! " << endl;
                }
                else if (xCarWeight > 20)
                {
               cout << "Car too heavy, you can not place it in queue! " << endl;
               }
               else if(xCarWeight < 0.386){

                cout << "Car too light, you can not place this car in queue! " << endl;
               }
               else
               {
             takeLine.insertLast(xCarType,xCarNumber,xCarManufactoringYear,xCarWeight);
             cout << endl;
             cout << "Insert performed successfully, press any key [info]..." << endl;
             }
             getchar();
             getchar();
             break;

             case 2:
             cout << "Operation [2]" << endl;
             takeLine.deleteFirst();
             cout << endl;
             cout << "The removal has been done successful, press any key [info]..." << endl;
             getchar();
             getchar();
             break;

             case 3:
             cout << "Operation [3]" << endl;
             takeLine.insertionSort();
             cout << endl;
             cout << "The removal has been successful, press any key [info]..." << endl;
             getchar();
             getchar();
             break;

             case 4:
             cout << "Operation [4]" << endl;
             takeLine.deleteMax();
             cout << endl;
             cout << "The removal has been done successful, press any key [info]..." << endl;
             getchar();
             getchar();
             break;

             case 5:
             cout << "Operation [5]" << endl;
             cout << "The current queue: " << endl;
             takeLine.showList();
             cout << endl;
             cout << "Printing has been done successfully, press any key [info]..." << endl;
             getchar();
             getchar();
              break;
              
              default:
              cout << "Goodbye :) ..." << endl;
               break;
             }
              } while (keyPass != 6);

    return 0;// function main end without problems
}//end of main function
