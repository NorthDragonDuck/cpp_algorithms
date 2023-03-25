
#include <iostream>
#include <vector>


using namespace std;
////////////////////////////////////////////////////////////////


char ask;
int table_counter =0;
void asker(){
		cout << "Would you like to insert new grade [y/N] ?"<< endl;
                    cin >> ask;
                    getchar();}
class StudMarks
{
public:
int StudEvaluation;
StudMarks* pNextMark;
public:
StudMarks(int cStudEva) : StudEvaluation(cStudEva), pNextMark(NULL)
{ }

void DisplayListElement() //display list
	{
		cout << " [ " << StudEvaluation << " ]"<< endl;
	}
};

 ////////////////////////////////////////////////////////////////
class StudLink
{
public:
string StudName;
string StudSurname;
StudMarks* pNextMark;
StudLink* pNextStud;
public:
StudLink(string cStudName, string cStudSurname) : StudName(cStudName), StudSurname(cStudSurname), pNextMark(NULL), pNextStud(NULL)
{ }
void DisplayListElement() //display list
	{
		cout << " " << StudName << " " << StudSurname;
	}
};
 ////////////////////////////////////////////////////////////////
//subject list
class SubLink
{
public:
	string subName;
    string sType;
    string sFeature; 
	StudLink* pNextStud;
	SubLink* pNext; 
				 //----------------------------------------------------------------
	SubLink(string csubName, string cType, string cFeature) : subName(csubName), sType(cType), sFeature(cFeature), pNext(NULL), pNextStud(NULL) //constructor
	{ }
	//----------------------------------------------------------------
	void displayLink() //display link
	{
		cout<< " - " << subName ;
	}

	void displayFullLink()//display link
	{
		cout << "Subject Name: [ " << subName << " ], Assessment type: [ " << sType << " ],"
 << " Purpose: [ " << sFeature << " ]" << endl;
	}

    
	//----------------------------------------------------------------
}; 
   ////////////////////////////////////////////////////////////////
class SortedList
{
private:
	SubLink* pFirst; //ref to first list item
	SubLink* pCurrent;
public:

	//----------------------------------------------------------------
	SortedList(): pFirst(NULL) //constructor
	{ }


//-------------------------------------------------------------
SubLink* find(string key) //find link
	{
	     pCurrent = pFirst;
						 //until end of list,
		while (pCurrent != NULL)//<
		{ //or key too small,

	
			if (pCurrent->subName == key) //is this the link
			
				{
					return pCurrent;
				
				} //found it, return link
			pCurrent = pCurrent->pNext; //go to next item
		}
		return NULL; //didn't find it
	}
//-------------------------------------------------------------

	void insertSubject(SubLink* pLink) 
	{ if(table_counter<50){
		pCurrent = pFirst;
		SubLink* pPrevious = NULL; 
		
			while (pCurrent != NULL)
		{ //or pCurrent > key,
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext; //go to next item
		}
		if (pPrevious == NULL) //if beginning of list,
			{pFirst = pLink;} // first -> new link
		else //not at beginning,
			{pPrevious->pNext = pLink; // prev -> new link
		pLink->pNext = pCurrent;
		} //new link -> current
         table_counter++;
}
else{
	cout << endl << "Sorry your hash table is full, you can not insert one more subject!" << endl;
}
	} //end insert()

	  //----------------------------------------------------------------
	void displayList()
	{
		cout << "List(first->last) : ";
		pCurrent = pFirst; //start at beginning of list
		while (pCurrent != NULL) //until end of list,
		{
			pCurrent->displayLink(); //print data
			pCurrent = pCurrent->pNext; //move to next link
		}
		cout << endl;
	}
	//----------------------------------------------------------------
	void displayStudMarks(StudMarks *pTempmarks)
	{
		if (pTempmarks != NULL) {
			StudMarks* pCurrent = pTempmarks;
			cout << "Mark is:" ;

				pCurrent->DisplayListElement();
		}else{
			cout << "Mark is: [ - ]" << endl;
		}
	
	}
//----------------------------------------------


void displayStudFromList(StudLink *pTempStud, bool action)
	{ int i=1;
		if (pTempStud != NULL) {
			StudLink* pCurrent = pTempStud;
			cout << "Students list:" << endl;

			while (pCurrent != NULL)
			{   cout <<  i << ".";
				pCurrent->DisplayListElement();
				cout << endl;
				if (action == true)
				{ 
					displayStudMarks(pCurrent->pNextMark);
				}
				
                
				pCurrent = pCurrent->pNextStud;
				i++;
			}
			cout << endl;
		}
	}

	//---------------------------------------

void displaySubStud(bool operation)
{
  pCurrent = pFirst;
		
		while (pCurrent != NULL)
		{
			pCurrent->displayLink();
			cout << endl;
			displayStudFromList(pCurrent->pNextStud, operation);

			pCurrent = pCurrent->pNext;
		}

}
//-------------------------------------------------------------
void displayByAssessment(string assessment){

pCurrent = pFirst;
		
		while (pCurrent != NULL)
		{

			if (pCurrent->sType== assessment){
			pCurrent->displayLink();
			cout << endl;
			}
		

			pCurrent = pCurrent->pNext;
		}

}
//-------------------------------------------------------------
void displayBySpecifiedPurpose(string feature){

pCurrent = pFirst;
		
		while (pCurrent != NULL)
		{

			if (pCurrent->sFeature == feature){
			pCurrent->displayLink();
			cout << endl;
			}
		

			pCurrent = pCurrent->pNext;
		}

}
}; //end class SortedList
   ////////////////////////////////////////////////////////////////
class HashTable
{
private:
	vector<SortedList*> hashArray; //vector of lists
	int arraySize;
	SubLink* pFound;
	SortedList access;
public:

	//----------------------------------------------------------------
	HashTable(int size) //constructor
	{
		arraySize = size;
		hashArray.resize(arraySize); //set vector size
		for (int j = 0; j<arraySize; j++) //fill vector
			hashArray[j] = new SortedList; //with lists
	}
	//----------------------------------------------------------------
	
	//----------------------------------------------------------------
	void displayTable()
	{
		for (int j = 0; j<arraySize; j++) //for each cell,
		{
			cout << j << "."; //display cell number
			hashArray[j]->displayList(); //display list
		}
	}
	//-------------------------------------------------------------
	void displayFunc2(){
cout << "List of  Subjects:" << endl;
		for (int j = 0; j<arraySize; j++) //for each cell,
		{
			
			hashArray[j]->displaySubStud(false); //display list
		}

	}
	//---------------------------------------------------------------
	void displayByAssess(string assess){
	 cout << endl << "List of  Subjects of the '" <<  assess << "' type of assessment:" << endl;
        for (int j = 0; j<arraySize; j++) //for each cell,
		{
		
			hashArray[j]->displayByAssessment(assess); //display list
		}

	}
	//---------------------------------------------------------------
	void displayByPurpose(string purpose){
     cout << endl <<  "List of  Subjects of the '" << purpose << "' purpose:" << endl;
		 for (int j = 0; j<arraySize; j++) //for each cell,
		{
		
			hashArray[j]->displayBySpecifiedPurpose(purpose); //display list
		}
	}
	//----------------------------------------------------------------
	void displayFunc7(string Subject){
       pFound =find(Subject);
		if(pFound != NULL){
		pFound ->displayFullLink();
		access.displayStudFromList(pFound->pNextStud, true);
		}else{
			 cout << endl <<  "Could not find '" << Subject << "'!" <<  endl;
		}
		
	}
	//----------------------------------------------------------------

	int hashFunc(string key)
{
int hashVal = 0;
for (int j = 0; j<key.length(); j++) //left to right
{
int letter = key[j] - 96; //get char code
hashVal = (hashVal * 27 + letter) % arraySize; //mod
}
if(hashVal<0){
			hashVal=hashVal*(-1);
		}
		
return hashVal; //no mod
} 
	//----------------------------------------------------------------
	SubLink* insertSubHash(string sSubject, string sType, string sPurpose) //insert a link
	{
		
		int hashVal = hashFunc(sSubject); //hash the key
		//44
        
	     pFound = find(sSubject);
		 if (pFound == NULL){
		SubLink *pDataItem = new SubLink(sSubject, sType, sPurpose);
		hashArray[hashVal]->insertSubject(pDataItem); //insert at hashVal
		 }
		 else
		 {
			 cout << endl << "This subject exist alredy!"<< endl;

		 }
		 
		 return pFound;
	} //end insert()
//----------------------------------------------------------------
	void insertStudHash(string key, string Name, string Surname,int mark, bool action){
	     pFound = find(key);
		 if (pFound != NULL){
	


	    StudLink* pNewLink = new StudLink(Name, Surname);
		StudLink* pPreviuos = NULL;
		StudLink* pCurrent = pFound->pNextStud; // pointing pCurrent to start li

        while (pCurrent != NULL )
		{ 
			pPreviuos = pCurrent; 
			pCurrent = pCurrent->pNextStud;
		}
		if (pPreviuos == NULL){ //new element is inserted at the begining of the list, becouse the pPreviuos==NULL
			pFound->pNextStud = pNewLink; 
			if(action==true){
				StudMarks*pNewMark = new StudMarks(mark);
             pFound->pNextStud->pNextMark = pNewMark;
			}
		 }
		else //new element is inserted not at the begining of the list
			{pPreviuos->pNextStud= pNewLink;
            if(action==true){
				StudMarks*pNewMark = new StudMarks(mark);
             pPreviuos->pNextStud->pNextMark = pNewMark;
			}
			}

		 }
				
			 else{
              cout << endl <<  "Could not find '" << key << "'!" <<  endl;
			 }
	

	  }
//-----------------------------------------------------------------
	  SubLink* find(string key){
		
		  int hashVal = hashFunc(key); //hash the key
		SubLink* pLink = hashArray[hashVal]->find(key); //get link
	
		return pLink; //return link
	  }
	  
//-----------------------------------------
void insertMarkForStud(string Subject, string Studname, string Studsurname, int Evaluation){
		
		bool additionalone = false;
		pFound = find(Subject);
		
          
	     if (pFound != NULL){
        StudLink* pPreviuos = NULL;
		StudLink* pCurrent = pFound->pNextStud; 
     
      while (pCurrent != NULL )
		{ 
	    
		if(pCurrent->StudName == Studname && pCurrent->StudSurname == Studsurname){
			
			 additionalone=true;
			 if(pCurrent->pNextMark ==NULL) {
			  StudMarks *pNewLink = new StudMarks(Evaluation);
			pCurrent->pNextMark = pNewLink; 
			 
			}
		else{ 
			cout << endl <<  "The current grade for " <<  Studname << " "<< Studsurname<< " is [ " << pCurrent->pNextMark->StudEvaluation << " ]" << endl;
			asker();
			
            if (ask == 'Y' || ask == 'y'){
          StudMarks* pTemp = pCurrent->pNextMark;
		  StudMarks *pNewLink = new StudMarks(Evaluation);
		  delete pTemp; 
		  pCurrent->pNextMark = pNewLink;
		  }
		 
		  }
		
		  }
		
		  	
        pPreviuos = pCurrent; 
			pCurrent = pCurrent->pNextStud;
		  
		}
if (additionalone==false){
	cout << endl << "Sorry " << Studname << " " << Studsurname << " does not exist!";
}
		}

		 else{
            cout << endl << "Could not find " << Subject <<"!"<< endl;

		 }
		
	  }
	//----------------------------------------------------------------
}; //end class HashTable
//-------------------------------------------------------------

void menuContents() {
cout << "Assignment 2, Task 19:" << endl;
cout << "-------------------------------------" << endl;
cout << "Select the operation you want to perform:" << endl;
cout << "-------------------------------------" << endl;
cout << "[1] Register the subject: " << endl;
cout << "[2] Print the list of subject sorted by name together with the list of listeners: " << endl;
cout << "[3] Print a list of subject of the specified type of assessment: " << endl;
cout << "[4] Print a list of subject of the specified purpose: " << endl;
cout << "[5] Register the listeners (to the specified subject) with or without a grade: " << endl;
cout << "[6] Register the grades of specified subject, while allowing to modify already entered grades: " << endl;
cout << "[7] Print the list of listeners of the subject together with the grades: " << endl;
cout << "[8] Display hash-table: "<< endl;
cout << "[9] Finish work: " << endl;
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
}
//-------------------------------------------------------------
	string xsubName;
    string xType;
    string xFeature; 
	string xStudName;
	string xStudSurname;
    
	int xStudEvaluation;
	bool check;
	
	void insertSubName(){
          cout << "Specify the subject name: Mathematics " << endl;
          cin >> xsubName;

	}

	void insertType(){
		 cout << "Specify the assessment type: exam, pass/non-pass " << endl;
         cin >> xType;
	}

	void insertFeature(){
		cout << "Specify the feature of purpose: general education, specialty" << endl;
        cin >> xFeature;
	}


void insertStudent(){
cout << "Specify the student name: James " << endl;
cin >> xStudName;
cout << "Specify the student surname: Jones " << endl;
cin >> xStudSurname;

}

void insertMark(){
	
	if (check == false){
cout << "Specify a grade for this student: 1-10 "  << endl;
}else
{
cout << "Try insert real grade: " << endl;	
}
cin >> xStudEvaluation ;
if (xStudEvaluation>10 || xStudEvaluation<0){
	check = true;
	insertMark();
	
}

}





   ////////////////////////////////////////////////////////////////
int main()
{   char response;// [Y/n]
	int keyPass;
    HashTable theHashTable(11);
  

     do {
          Menu(&keyPass);
           switch (keyPass) 
           {
             case 1:
             cout << "Operation [1]" << endl << endl;
             insertSubName();
			 insertType();
			 insertFeature();
			 
			 theHashTable.insertSubHash(xsubName, xType, xFeature );
             cout << endl <<"Press enter key [info]..." << endl;
             getchar();
             getchar();
             break;

             case 2:
             cout << "Operation [2]" << endl << endl;
			 theHashTable.displayFunc2();
			 
             cout << endl << "Press enter key [info]..." << endl;
             getchar();
             getchar();
             break;

             case 3:
             cout << "Operation [3]" << endl <<  endl;
             insertType();
		     theHashTable.displayByAssess(xType);
             cout << endl << "Press enter key [info]..." << endl;
             getchar();
             getchar();
             break;

             case 4:
             cout << "Operation [4]" << endl << endl;
             insertFeature();
			 theHashTable.displayByPurpose(xFeature);
             cout << endl << "Press enter key [info]..." << endl;
             getchar();
             getchar();
             break;

             case 5:
             cout << "Operation [5]" << endl << endl;
			  insertSubName();
			  
			  insertStudent();
			cout <<  "Would you like to insert new student with grade [y/N] ?"<< endl;
                    cin >> response;
                   
					if(response=='Y' || response=='y'){
						getchar();
						insertMark();
              theHashTable.insertStudHash(xsubName, xStudName,xStudSurname,xStudEvaluation, true);
			  }else{
				 theHashTable.insertStudHash(xsubName, xStudName,xStudSurname,12 , false); 
			  }
             cout << endl << "Press enter key [info]..." << endl;
             getchar();
             getchar();
              break;
              
             case 6:
             cout << "Operation [6]" << endl << endl;
			 insertSubName();
		
			 insertStudent();
             insertMark();
			theHashTable.insertMarkForStud(xsubName, xStudName, xStudSurname, xStudEvaluation);
             cout << endl << "Press enter key [info]..." <<  endl;
             getchar();
             getchar();
              break;


			  case 7:
             cout << "Operation [7]" << endl << endl;
                insertSubName();
				cout << endl;
              theHashTable.displayFunc7(xsubName);
        
             cout << endl <<  "Press enter key [info]..." << endl;
             getchar();
             getchar();
              break;

			    case 8:
             cout << "Operation [8]" << endl << endl;
        theHashTable.displayTable();
             cout << endl << "Press enter key [info]..." << endl;
             getchar();
             getchar();
              break;


              default:
              cout << "Goodbye :) ..." << endl;
               break;
             }
              } while (keyPass != 9);
	
	return 0;
} //end main()