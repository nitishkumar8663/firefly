#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define STMNT fscanf(fp,"%c",&ch)

struct complex1 { int real, img;};
int pgm_no,num_of_variables,lb,ub,num_of_paths=0,significant_path_count=0,insignificant_path_count=0,iter,num_of_nodes=0,num_of_prednodes=0,num_lines=0, iterations=0,fit_access=0,red_path_count=0;
int nodes_covered[500],path[500][500],test_case[500][500] ,temp_path1[500],fitness[500],test[500],red_path[500][500],red_test_case[500][500];

void initialize()
{
	int i,j;
	for(i=0;i<500;i++)
	{
		nodes_covered[i]=0;
		//temp_path1[i]=-1;
		fitness[i]=0;
	//	temp_path2[i]=-1;
	}
	for(i=0;i<500;i++)
	{
		for(j=0;j<500;j++)
		{
			path[i][j]=-1;
			red_path[i][j]=-1;
			test_case[i][j]=0;
			red_test_case[i][j]=0;
		}
	}
}

void init_sl()
{
	if(pgm_no==1)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(1);
		int j = 100;
	}
	if(pgm_no==2)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(2);
		int j = 100;
	}
	if(pgm_no==3)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(2);
		int j = 100;
	}
	if(pgm_no==4)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(3);
		int j = 100;
	}
	if(pgm_no==5)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(3);
		int j = 100;
	}
	if(pgm_no==6)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(3);
		int j = 100;
	}
	if(pgm_no==7)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(4);
		int j = 100;
	}
	if(pgm_no==8)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(4);
		int j = 100;
	}
	if(pgm_no==9)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(4);
		int j = 100;
	}
	if(pgm_no==10)
	{
		cout<<".";
		int linenumber = 0;
		int k=0; sleep(5);
		int j = 100;
	}
} 

void init_path()
{
	int i;
	for(i=0;i<500;i++)
	{
		temp_path1[i]=-1;
	}
}

void CFG()
{
  int paranthesis[500],predicate[500][2],num_of_prednodes=0,nodes[500];
  for(int i=0;i<500;i++)
{
	paranthesis[i]=0;
	predicate[i][0]=-1;
	predicate[i][1]=-1;
	nodes[i]=0;
}
  FILE *fp;
  int paran,k=0,line_no,cyclometric_complexity;
  char ch,prev;  

//initialize();
fp=fopen("C:\\Users\\nitish\\Desktop\\Major Implementation\\Program1.txt","r");
//printf("Open successful");
fscanf(fp,"%c",&ch);

//Start at first Opening Bracket
while(ch!='{')
{
	STMNT;
}
prev='{';
line_no=1;
paran=1;
//Scan till end of File
  while(fscanf(fp,"%c",&ch)!=EOF)
  {
  	//printf("%c",ch);
  	if(ch==';')
  	line_no++;
  	if(ch=='{')
  	{	
		line_no++;
		paran++; 
	}
	if(ch=='}')
  	{	
		line_no++;
		paran--; 
		if(paranthesis[paran]!=0)
		{
			int i=0;
			while(predicate[i][0]!=paranthesis[paran])
			i++;
			predicate[i][1]=line_no+1;
		}
	}
  	if(!isalnum(prev))
  	{ 
     if(ch=='i')
     {
       STMNT;
       //printf(":%c",ch);
       if(ch=='f')
       {
       	STMNT;
       	if(ch=='('||ch==' ')
       {
       	//printf("Here");
      num_of_prednodes++;
      while(ch!='\n')
      STMNT;
      line_no++;
      predicate[num_of_prednodes-1][0]=line_no;
      paranthesis[paran]=line_no;
       }
       }
     }
     else if(ch=='w')
     {
    STMNT;
    if(ch=='h')
    {
      STMNT;
      if(ch=='i')
      {
        STMNT;
        if(ch=='l')
        {
          STMNT;
          if(ch=='e')
          {
           STMNT;
       	if(ch=='('||ch== ' ')
       {
       	//printf("Here");
      num_of_prednodes++;
      while(ch!='\n')
      STMNT;
      line_no++;
      predicate[num_of_prednodes-1][0]=line_no;
      paranthesis[paran]=line_no;
       }
          }
        }
      }
    }
      }
      else if(ch=='f')
      {
    STMNT;
    if(ch=='o')
    {
      STMNT;
      if(ch=='r')
      {
        STMNT;
       	if(ch=='('||ch==' ')
       {
       	//printf("Here");
      num_of_prednodes++;
      while(ch!='\n')
      STMNT;
      line_no++;
      predicate[num_of_prednodes-1][0]=line_no;
      paranthesis[paran]=line_no;
       }
      }
    }
      }
      
  }
  prev=ch;
}
fclose(fp);
nodes[0]=1;
k=0;
for(int i=1,j=0;i<=line_no;i++)
{
	//cout<<"\ni"<<i;
	if(j<num_of_prednodes&&predicate[j][0]==i)
	{
		nodes[++k]=i;
		//cout<<"\nNode:"<<nodes[k];
		
		if(predicate[j][0]!=i+1)
		{
			nodes[++k]=i+1;
		//cout<<"\nNode:"<<nodes[k];
		}
		nodes[++k]=predicate[j][1];
		//cout<<"\nNode:"<<nodes[k];
		j++;
	}
}
sort(nodes,nodes+k+1);
//num_of_nodes=k+1;
//cout<<"\nNo of Nodes = "<<num_of_nodes;
cyclometric_complexity=num_of_prednodes+1; 
 
  for(int i=0;i<num_of_prednodes;i++)
  {
  	cout<<"\nPredicate node at : "<<predicate[i][0]<<" Next statement at : "<<predicate[i][1];
  }
  //printf("\nNumber of lines =%d",line_no);
  //printf("\nCyclometic Complexity is = ");
  //printf("\t %d",cyclometric_complexity);
cout<<"\n\n";
cout<<"\t\tStart\n";
for(int i=0,j=0;i<=k;i++)
{cout<<"\t\t|\n";
cout<<"\t\tv\n";
cout<<"\t\t(S"<<i+1<<")"<<nodes[i];
if(j<num_of_prednodes&&nodes[i]==predicate[j][0])
{
	cout<<"-->"<<predicate[j][1];
	j++;
}
cout<<"\n";
}
cout<<"\t\t|\n\t\tv\n\t\tEnd";
//getch();
}

void initial()
{
	initialize();
	srand(time(NULL));
	for(int i=0;i<num_of_variables;i++)
	{
		double scaled = (double)rand()/RAND_MAX;
		test_case[0][i]= (ub - lb +1)*scaled + lb;
		cout<<test_case[0][i]<<" ";
		test[i]=test_case[0][i];
	}
	//clrscr();
	system("cls");
	CFG();
	cout<<"\n\nLoading.";
}

void introMsg()
{
	cout<<"````````````````Welcome to Automatic Test Case Generator``````````````\n\n";
	cout<<"\t\tThe List of Programs is as follows\n";
	cout<<"\t\t1.Triangle\n\t\t2.Student Grading System\n\t\t3.Telecom Billing System\n";
	cout<<"\t\t4.Complex Numers\n\t\t5.Matrix Operations\n\t\t6.Leap Year\n";
	cout<<"\t\t7.Numbers from Character\n\t\t8.Range of Numbers Program\n\t\t9.Date Month Program\n\t\t10.Scientific Calculator\n\nEnter the Program Number : ";
	cin>>pgm_no;
	cout<<"Enter the number of variables ";
	cin>>num_of_variables;
	cout<<"Enter the lower and upper range ";
	cin>>lb>>ub;
	initial();
}

void triangle();
void grade_student();
void telecom(); 
void complex_numbers();
void matrix_op();
void leap_year();
void num_from_char();
void range();
void date_month();
void calculator();

void find_path()
{
	if(pgm_no==1)
	triangle();
	if(pgm_no==2)
	grade_student();
	if(pgm_no==3)
	telecom();
	if(pgm_no==4)
	complex_numbers();
	if(pgm_no==5)
	matrix_op ();
	if(pgm_no==6)
	leap_year();
	if(pgm_no==7)
	num_from_char();
	if(pgm_no==8)
	range();
	if(pgm_no==9)
	date_month();
	if(pgm_no==10)
	calculator(); init_sl();
}

void leap_year () {
 	init_path();
    int linenumber = 0,k=0;
 
    int a,b,c,d,e; linenumber++; temp_path1[k++] = linenumber;
    linenumber++; temp_path1[k++]=linenumber;
 
    a = test[0]; linenumber++; temp_path1[k++]=linenumber;
 
    if ( a%4 == 0 ) {
        linenumber++; temp_path1[k++]=linenumber;
 
        if ( a %100 == 0 ) {
 
        	linenumber++; temp_path1[k++]=linenumber;
 
        	 if ( a%400 == 0 ) {
        	 	 // leap year
        	 	 linenumber++; temp_path1[k++]=linenumber;
        	 }
        	 else
        	  {
        	  	// not a leap year
        	  	linenumber += 2;
        	  }
        }
        else {
        	// not a leap year
        	linenumber += 5;
        }
 
    }
 
    else {
    	linenumber += 7;
    }
 
    linenumber++; temp_path1[k++]=linenumber;
    num_lines = linenumber;
 
}
 
 
void num_from_char () {
 	init_path();
    int linenumber = 0,i,k=0;
 
    linenumber++; temp_path1[k++]=linenumber;
 
    int a[27]; linenumber++; temp_path1[k++]=linenumber;
    int temp_path[500];  linenumber++; temp_path1[k++]=linenumber;
 
	for ( i=0; i<26; i++ ) {
		a[i] = test[i];
		linenumber++;
		temp_path1[k++] = linenumber;
	}
 
	int htest = test[26]; linenumber++; temp_path1[k++]=linenumber;
 
	if ( htest == test[0] ) {
		// cout << "The given chaacter is (char)(i+97) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[1] ) {
		// cout << "The given chaacter is (char)(i+98) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[2] ) {
		// cout << "The given chaacter is (char)(i+99) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[3] ) {
		// cout << "The given chaacter is (char)(i+100) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[4] ) {
		// cout << "The given chaacter is (char)(i+101) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[5] ) {
		// cout << "The given chaacter is (char)(i+102) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[6] ) {
		// cout << "The given chaacter is (char)(i+103) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[7] ) {
		// cout << "The given chaacter is (char)(i+104) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[8] ) {
		// cout << "The given chaacter is (char)(i+105) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[9] ) {
		// cout << "The given chaacter is (char)(i+106) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[10] ) {
		// cout << "The given chaacter is (char)(i+107) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[11] ) {
		// cout << "The given chaacter is (char)(i+108) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[12] ) {
		// cout << "The given chaacter is (char)(i+109) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[13] ) {
		// cout << "The given chaacter is (char)(i+110) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[14] ) {
		// cout << "The given chaacter is (char)(i+111) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[15] ) {
		// cout << "The given chaacter is (char)(i+116) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[16] ) {
		// cout << "The given chaacter is (char)(i+117) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
	if ( htest == test[17] ) {
		// cout << "The given chaacter is (char)(i+118) " ; 
		linenumber++; temp_path1[k++]=linenumber;
	}
	else {
		linenumber += 2;
	}
 
    linenumber++; temp_path1[k++]=linenumber;
    num_lines = linenumber;
 
}
 
 
void range () {
 
    int linenumber = 0,k=0;
 
    int a = test[0]; linenumber++; temp_path1[k++] = linenumber;
 
    if ( a >0 && a<= 10 ) {
    	// in (1,10)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >10 && a<= 20 ) {
    	// in (10,20)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >20 && a<= 30 ) {
    	// in (20,30)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >30 && a<= 40 ) {
    	// in (30,40)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >40 && a<=50 ) {
    	// in (40,50)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >50 && a<= 60 ) {
    	// in (50,60)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >60 && a<=70 ) {
    	// in (60,70)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >70 && a<= 80 ) {
    	// in (70,80)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >80 && a<= 90 ) {
    	// in (80,90)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >90 && a<=100 ) {
    	// in (90,100)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a >100 && a<= 110 ) {
    	// in (100,110)
    	linenumber++; temp_path1[k++]=linenumber;
    }
    else 
    	linenumber += 2;
 
    if ( a > 100 && a <= 110 ) {
 
    	// in (100,110)
    	linenumber++; temp_path1[k++]=linenumber;
 
    	int rem = a%10; linenumber++; temp_path1[k++]=linenumber;
 
    	if ( rem == 1 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    	if ( rem == 2 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    	if ( rem == 3 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    	if ( rem == 4 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    	if ( rem == 5 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    	if ( rem == 6 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    	if ( rem == 1 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    	if ( rem == 7 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    	if ( rem == 8 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    	if ( rem == 9 ) {
    		// last digit is 1 
    		linenumber++; temp_path1[k++]=linenumber;
    	}
    	else
    		linenumber += 2;
 
    }
    else 
    	linenumber += 42;
 
    linenumber++; temp_path1[k++]=linenumber;
    num_lines = linenumber;
 
}
 
void date_month () {
 	init_path();
    int linenumber = 0,k=0;
 
    int a,b; linenumber++; temp_path1[k++] = linenumber;
 
    a = test[0], b = test[1] ; linenumber++; temp_path1[k++]=linenumber;
 
	if ( a == 1 ) {
		//cout << "The date is 1 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 1 ) {
		//cout << "The date is 1 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 2 ) {
		//cout << "The date is 2 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 3 ) {
		//cout << "The date is 3 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 4 ) {
		//cout << "The date is 4 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 5 ) {
		//cout << "The date is 5 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 6 ) {
		//cout << "The date is 6 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 7 ) {
		//cout << "The date is 7 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 8 ) {
		//cout << "The date is 1 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 1 ) {
		//cout << "The date is 8 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 9 ) {
		//cout << "The date is 9 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 10 ) {
		//cout << "The date is 10 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 11 ) {
		//cout << "The date is 11 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 12 ) {
		//cout << "The date is 12 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( a == 13 ) {
		//cout << "The date is 13 \n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber+= 2;
 
	if ( b ==1 ) {
		//cout << "Month is jan\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b ==2 ) {
	//	cout << "Month is feb\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b == 3) {
	//	cout << "Month is march\n";
	linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b == 4 ) {
	//	cout << "Month is april\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b ==5 ) {
	//	cout << "Month is may\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b == 6 ) {
		//cout << "Month is june\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b ==7 ) {
		//cout << "Month is july\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b ==8 ) {
		//cout << "Month is aug\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b ==9 ) {
		//cout << "Month is sep\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b ==10 ) {
	//	cout << "Month is oct\n";
	linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b ==11 ) {
		//cout << "Month is nov\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
	if ( b ==12 ) {
		//cout << "Month is dec\n";
		linenumber++; temp_path1[k++] = linenumber;
	}
	else
		linenumber += 2;
 
    linenumber++; temp_path1[k++]=linenumber;
    num_lines = linenumber;
 
}
 
void calculator () {
 	init_path();
//    init_path();
    int linenumber = 0,k=0;
 
    int a,b,c,d,e; linenumber++; temp_path1[k++] = linenumber;
    linenumber++; temp_path1[k++]=linenumber;
 
    // a = are the numbers real or imaginary? a = 1: real else a = 0 means imaginary
 
    a = test[0], b = test[1], c = test[2], d = test[3]; linenumber++; temp_path1[k++]=linenumber;
 
    if ( a == 1 ) {
        // numbers are real
        linenumber++; temp_path1[k++]=linenumber;
 
        if ( c == 1 ) {
                // performing addition
            linenumber++; temp_path1[k++]=linenumber;
        }
        else {
            linenumber += 2;
        }
 
        if ( c == 2 ) {
                // performing subtraction
            linenumber++; temp_path1[k++]=linenumber;
        }
        else
            linenumber += 2;
 
        if ( c == 3 ) {
                // performing multiplication
            linenumber++; temp_path1[k++]=linenumber;
        }
        else {
            linenumber += 2;
		}
 
        if ( c == 4 ) {
                // performing division
            linenumber++; temp_path1[k++]=linenumber;
        }
        else 
        	linenumber += 2;
 
    }
    else {
        // numbers are imaginary. Normal calc can't add.
        linenumber+=9; temp_path1[k++] = linenumber;
    }
 
    linenumber++; temp_path1[k++]=linenumber;
    num_lines = linenumber;
}

void triangle()
{
	init_path();
	int linenumber=0,k=0;
	//starts here
	int a,b,c,flag=0; linenumber++; temp_path1[k++]=linenumber;
	//cout<<"temp_path"<<temp_path1[0];
	printf(""); linenumber++; temp_path1[k++]=linenumber;
	a=test[0],b=test[1],c=test[2]; linenumber++; temp_path1[k++]=linenumber;
	linenumber++; temp_path1[k++]=linenumber;
	if (   ( a < ( b + c ) ) && ( b < ( c + a ) ) && ( c < ( a + b ) ) ) 
	{
	 if ( (a==b) && (b==c) )
	{
		linenumber++; temp_path1[k++]=linenumber;
		linenumber++; temp_path1[k++]=linenumber;
	}
	else linenumber+=2;
	 if ( (a!=b) && (b!=a) && (c!=b)) 
	 {
	 	linenumber++; temp_path1[k++]=linenumber;
	 	linenumber++; temp_path1[k++]=linenumber;
	 }
	 else linenumber+=2;
	if(a==b)
	{
		linenumber++; temp_path1[k++]=linenumber;
	 	linenumber++; temp_path1[k++]=linenumber;
	}
	else linenumber+=2;
	if (b==c)
	{
		linenumber++; temp_path1[k++]=linenumber;
	 	linenumber++; temp_path1[k++]=linenumber;
	}
	else linenumber+=2;
	if (c==a)
	{
		linenumber++; temp_path1[k++]=linenumber;
	 	linenumber++; temp_path1[k++]=linenumber;
	}
	else linenumber+=2;
	//cout<<linenumber;
	linenumber++; temp_path1[k++]=linenumber;
	}
	else {
	linenumber=16; temp_path1[k++]=linenumber;	
	if  (a >= (b + c))
	{
		linenumber++; temp_path1[k++]=linenumber;
	 	linenumber++; temp_path1[k++]=linenumber;
	}
	else linenumber+=2;
	if ( b>= (c + a) )
	{
		linenumber++; temp_path1[k++]=linenumber;
	 	linenumber++; temp_path1[k++]=linenumber;
	}
	else linenumber+=2;
	if ( c >= (a + b ) )
	{
		linenumber++; temp_path1[k++]=linenumber;
	 	linenumber++; temp_path1[k++]=linenumber;
	}
	else linenumber+=2;
	//cout<<linenumber;
	//linenumber++; temp_path1[linenumber]=1;
	}

	linenumber=24; temp_path1[k++]=linenumber;
	num_lines=linenumber;
	//cout<<"Lines"<<num_lines<<"\n";
}

void grade_student () {
 
    init_path();
    int linenumber = 0,k=0;
 
    int a,b,c,d,e; linenumber++; temp_path1[k++] = linenumber;
    
    linenumber++; temp_path1[k++]=linenumber;
    a = test[0], b = test[1], c = test[2], d = test[3], e = test[4]; linenumber++; temp_path1[k++]=linenumber;
    int avg = (a+b+c+d+e)/5; linenumber++; temp_path1[k++]=linenumber;
 
 
    if ( avg >= 85 ) {
        linenumber++; temp_path1[k++]=linenumber;
        linenumber++; temp_path1[k++]=linenumber;
    }
    else {
        linenumber += 2;
    }
 
    if ( avg >=60 && avg < 85 ) {
    	linenumber++;temp_path1[k++]=linenumber;
        linenumber++; temp_path1[k++]=linenumber;
    }
    else
        linenumber += 2;
 
    if ( avg >=40 && avg < 60 ) {
    	linenumber++;temp_path1[k++]=linenumber;
        linenumber++; temp_path1[k++]=linenumber;
    }
    else
        linenumber += 2;
 
    if ( avg <40 ) {
    	linenumber++;temp_path1[k++]=linenumber;
        linenumber++; temp_path1[k++]=linenumber;
    }
    else
    	linenumber+=2;
 
    linenumber++; temp_path1[k++]=linenumber;
    num_lines = linenumber;
 
}

void telecom()
{
	init_path();
	int linenumber=0,k=0;
	//starts here
    int calls,a,b,c; linenumber++; temp_path1[k++]=linenumber;
    float bill; linenumber++; temp_path1[k++]=linenumber;

    linenumber++; temp_path1[k++]=linenumber;
    calls = test[0], a=test[1]/2, b= test[2]/3, c= test[3]/4; linenumber++; temp_path1[k++]=linenumber;
    
    if (calls <= a)
    {
    	linenumber++; temp_path1[k++]=linenumber;
        bill = 200; linenumber++; temp_path1[k++]=linenumber;
    }
    else if ((calls > a) && (calls <= (a+b)))
    {
    	linenumber+=3; temp_path1[k++]=linenumber;
        calls = calls - 100; linenumber++; temp_path1[k++]=linenumber;
        bill = 200+(0.60 *calls);linenumber++; temp_path1[k++]=linenumber;
    }
    else if (calls > 150 && calls <= 200)
    {
    	linenumber+=6; temp_path1[k++]=linenumber;
        calls = calls - 150; linenumber++; temp_path1[k++]=linenumber;
        bill = 200+(0.60 *50) + (0.50 *calls); linenumber++; temp_path1[k++]=linenumber;
    }
    else
    {
    	linenumber+=9; temp_path1[k++]=linenumber;
        calls = calls - 200; linenumber++; temp_path1[k++]=linenumber;
        bill = 200 + (0.60 * 50) + (0.50 * 50) + (0.40 * calls); linenumber++; temp_path1[k++]=linenumber;
    }

    linenumber=16; temp_path1[k++]=linenumber;
	num_lines=linenumber;
}

 
void complex_numbers()
{
  int linenumber=0,k=0;
  init_path();	
  int choice, temp1, temp2, temp3; linenumber++; temp_path1[k++]=linenumber;
   struct complex1 a, b, c; linenumber++; temp_path1[k++]=linenumber;
 
    //printf("Press 1 to add two complex numbers.\n"); 
	linenumber++; temp_path1[k++]=linenumber;
    //printf("Press 2 to subtract two complex numbers.\n"); 
	linenumber++; temp_path1[k++]=linenumber;
    //printf("Press 3 to multiply two complex numbers.\n"); 
	linenumber++; temp_path1[k++]=linenumber;
    //printf("Press 4 to divide two complex numbers.\n"); 
	linenumber++; temp_path1[k++]=linenumber;
    //printf("Press 5 to exit.\n"); 
	linenumber++; temp_path1[k++]=linenumber;
    //printf("Enter your choice\n"); 
	linenumber++; temp_path1[k++]=linenumber;
    //scanf("%d",&choice);
 	choice = test[0]; linenumber++; temp_path1[k++]=linenumber;
    if( choice == 5)
    {
    	linenumber++; temp_path1[k++]=linenumber;
    	linenumber++; temp_path1[k++]=linenumber;
	}
 
    if(choice >= 1 && choice <= 4)
    {
      linenumber+=2; temp_path1[k++]=linenumber;
      //printf("Enter a and b where a + ib is the first complex number.");
      linenumber++; temp_path1[k++]=linenumber;
	  //printf("\na = ");
      linenumber++; temp_path1[k++]=linenumber;
	  //scanf("%d", &a.real);
      a.real = test[1]; linenumber++; temp_path1[k++]=linenumber;
	  //printf("b = ");
      //scanf("%d", &a.img);
      a.img = test[2]; linenumber++; temp_path1[k++]=linenumber;
	  //printf("Enter c and d where c + id is the second complex number.");
      //printf("\nc = ");
      linenumber++; temp_path1[k++]=linenumber;
      //scanf("%d", &b.real);
      b.real = test[3]; linenumber++; temp_path1[k++]=linenumber;
	  //printf("d = ");
      //scanf("%d", &b.img);
      b.img = test[4]; linenumber++; temp_path1[k++]=linenumber;
    }
    if ( choice == 1 )
    {
    	linenumber=20; temp_path1[k++]=linenumber;
      c.real = a.real + b.real; linenumber++; temp_path1[k++]=linenumber;
      c.img = a.img + b.img; linenumber++; temp_path1[k++]=linenumber;
 
      if ( c.img >= 0 ) 
      {
      	linenumber++; temp_path1[k++]=linenumber;
      	linenumber++; temp_path1[k++]=linenumber;
	  }
         else
         {
         	linenumber+=3; temp_path1[k++]=linenumber;
         	linenumber++; temp_path1[k++]=linenumber;
		 }
        
    }
    else if ( choice == 2 )
    {
    	linenumber=27; temp_path1[k++]=linenumber;
      c.real = a.real - b.real; linenumber++; temp_path1[k++]=linenumber;
      c.img = a.img - b.img; linenumber++; temp_path1[k++]=linenumber;
 
      if ( c.img >= 0 )
      {
      	linenumber++; temp_path1[k++]=linenumber;
      	linenumber++; temp_path1[k++]=linenumber;
	  }
         else
         {
         	linenumber++; temp_path1[k++]=linenumber;
         	linenumber+=3; temp_path1[k++]=linenumber;
		 }
        
    }
    else if ( choice == 3 )
    {
    	linenumber=34; temp_path1[k++]=linenumber;
      c.real = a.real*b.real - a.img*b.img; linenumber++; temp_path1[k++]=linenumber;
      c.img = a.img*b.real + a.real*b.img; linenumber++; temp_path1[k++]=linenumber;
 
      if ( c.img >= 0 )
      {
      	linenumber++; temp_path1[k++]=linenumber;
	  }
        
      else
      {
      	linenumber++; temp_path1[k++]=linenumber;
      	linenumber++; temp_path1[k++]=linenumber;
	  }
        
    }
    else if ( choice == 4 )
    {
    	linenumber=41; temp_path1[k++]=linenumber;
      if ( b.real == 0 && b.img == 0 )
      {
      	linenumber++; temp_path1[k++]=linenumber;
      	linenumber++; temp_path1[k++]=linenumber;
	  }
      else
      {
      	linenumber+=3; temp_path1[k++]=linenumber;
        temp1 = a.real*b.real + a.img*b.img; linenumber++; temp_path1[k++]=linenumber;
        temp2 = a.img*b.real - a.real*b.img; linenumber++; temp_path1[k++]=linenumber;
        temp3 = b.real*b.real + b.img*b.img; linenumber++; temp_path1[k++]=linenumber;
 
        if ( temp1%temp3 == 0 && temp2%temp3 == 0 )
        {
        	linenumber++; temp_path1[k++]=linenumber; 
          if ( temp2/temp3 >= 0)
          {
            linenumber++; temp_path1[k++]=linenumber;
			linenumber++; temp_path1[k++]=linenumber;	
		  }
          else
          {
          	linenumber+=3; temp_path1[k++]=linenumber;
          	linenumber++; temp_path1[k++]=linenumber;
		  }
            
        }
        else if ( temp1%temp3 == 0 && temp2%temp3 != 0 )
        {
        	linenumber+=6; temp_path1[k++]=linenumber;
          if ( temp2/temp3 >= 0)
          {
          	linenumber++; temp_path1[k++]=linenumber;
          	linenumber++; temp_path1[k++]=linenumber;
		  }
            
          else
          {
          	linenumber+=3; temp_path1[k++]=linenumber;
          	linenumber++; temp_path1[k++]=linenumber;
		  }
            
        }
        else if ( temp1%temp3 != 0 && temp2%temp3 == 0 )
        {
        	linenumber+=12; temp_path1[k++]=linenumber;
          if ( temp2/temp3 >= 0)
           {
           	linenumber++; temp_path1[k++]=linenumber;
           	linenumber++; temp_path1[k++]=linenumber;
		   }
          else
          {
          	linenumber+=3; temp_path1[k++]=linenumber;
          	linenumber++; temp_path1[k++]=linenumber;
		  }
        }
        else
        {
        	linenumber+=18; temp_path1[k++]=linenumber;
          if ( temp2/temp3 >= 0)
           {
           	linenumber++; temp_path1[k++]=linenumber;
		   }
          else
          {
          	linenumber++; temp_path1[k++]=linenumber;
		  }
        }
      }
    }
    else
    {
    	linenumber=66; temp_path1[k++]=linenumber;	
	}
    
    linenumber=67; temp_path1[k++]=linenumber;
    num_lines=linenumber;
}

void matrix_op () {
 
    init_path();
    int linenumber = 0,ch,k=0;
 
    int a1,b1,c1,d1,a2,b2,c2,d2; linenumber++; temp_path1[k++] = linenumber;
    linenumber++; temp_path1[k++]=linenumber;
    a1 = test[0], b1 = test[1], c1 = test[2], d1 = test[3], a2 = test[4], b2 = test[5], c2 = test[6], d2 = test[7]; linenumber++; temp_path1[k++]=linenumber;
 
    //cout << "MENU : \n"; 
	linenumber++; temp_path1[k++]=linenumber;
    //cout << "1. Addition of two matrices \n"; 
	linenumber++; temp_path1[k++]=linenumber;
    //cout << "2. Subtraction of two matrices \n"; 
	linenumber++; temp_path1[k++]=linenumber;
    //cout << "3. Take transpose of the matrix \n"; 
	linenumber++; temp_path1[k++]=linenumber;
 
    //cout << "Enter your choice \n"; 
	linenumber++; temp_path1[k++]=linenumber;
 
    ch = test[8]; linenumber++; temp_path1[k++]=linenumber;
 
    if ( ch == 1 ) {
        linenumber++; temp_path1[k++]=linenumber;
       // cout << "The result of addition : "  << (a1+ a2) <<"," << b1+b2 <<","<< c1+c2 <<"," << d1+d2 << endl; 
	   linenumber++; temp_path1[k++]=linenumber;
    }
    else if ( ch == 2 ) {
        linenumber+=3; temp_path1[k++]=linenumber;
        //cout << "Subtraction of two matrices : " << (a1-a2) <<"," << b1-b2 <<","<< c1-c2 <<"," << d1-d2 << endl; 
		linenumber++; temp_path1[k++]=linenumber;
    }
    else if ( ch == 3 ) {
        linenumber += 6; temp_path1[k++]=linenumber;
       // cout << "The transpose is : " << a1 <<" " << c1 <<" " << b1 <<" " << d1 << endl;
	    linenumber++; temp_path1[k++]=linenumber;
    }
    linenumber=16; temp_path1[k++]=linenumber;
    num_lines = linenumber;
}

void assign_fitness()
{
	int i,cc=10;
	num_of_nodes=num_lines;
	for(i=0;i<num_lines;i++)
	{
/*
		if(node is predicate
		if(i+1==predicate[k][0])
		{
			cc--;
			k++;	
		}
*/
			srand(time(NULL));
			float temp=1000/(cc*((num_lines-i-1)*10+(rand() %10)));
			fitness[i]=temp;
			fit_access++;
			//cout<<fitness[i]<<"\n";
	}
}

//flg=0 fitness of path
// flg = 1 fitness of temp_path
int find_fitness(int flg)
{
	int i=0,fit=0;
	if(!flg)
	{
		while(temp_path1[i]!=-1)
		{
			fit_access++;
			path[0][i]=temp_path1[i];
			nodes_covered[path[0][i]]=1;
			fit+=fitness[path[0][i]];	
			i++;
		}	
	}
	else
	{
		while(temp_path1[i]!=-1)
		{
			fit+=fitness[temp_path1[i]];	
			i++;
		}
	}
	/*i=0;
	while(temp_path1[i]!=-1)
	{
		cout<<temp_path1[i];
		i++;
	}*/
	return fit;
}
int find_new_node();
void assign_path()
{
	int k=0;
	find_path();
	int new_node = find_new_node();
	if(new_node > 0)
	{
		//cout<<"Here";
					significant_path_count++;
					k=0;
					while(temp_path1[k]!=-1)
					{
						path[num_of_paths][k]=temp_path1[k];
						k++;
					}
					for(k=0;k<num_of_variables;k++)
					{
						test_case[num_of_paths][k] = test[k];
					}
					int new_fitness = find_fitness(1);
					fit_access++;
					fitness[num_of_paths]=new_fitness;
					num_of_paths++;	
				
	}
	else
				{
					//cout<<"inHere";
					if(insignificant_path_count<50)
					{
						//insignificant_path_count++;
						k=0;
						while(temp_path1[k]!=-1)
						{	
							red_path[insignificant_path_count][k]=temp_path1[k];
							k++;
						}
							
					
					for(k=0;k<num_of_variables;k++)
					{
						red_test_case[insignificant_path_count][k] = test[k];
					} 
					insignificant_path_count++;	
				}
				}
				
}

void more_test_cases()
{
	int i=0,j=0;
	iterations++;
	while(j<num_of_variables)
	{
		//cout<<"Here";
		test[j]=lb;
		for(i=0;i<num_of_variables;i++)
		{
			if(i!=j)
			test[i]=(lb+ub)/2;
		}
		assign_path();	
		test[j]=lb+1;
		for(i=0;i<num_of_variables;i++)
		{
			if(i!=j)
			test[i]=(lb+ub)/2;
		}
		assign_path();	
		test[j]=(lb+ub)/2;
		for(i=0;i<num_of_variables;i++)
		{
			if(i!=j)
			test[i]=(lb+ub)/2;
		}
		assign_path();	
		test[j]=ub-1;
		for(i=0;i<num_of_variables;i++)
		{
			if(i!=j)
			test[i]=(lb+ub)/2;
		}
		assign_path();	
		test[j]=ub;
		for(i=0;i<num_of_variables;i++)
		{
			if(i!=j)
			test[i]=(lb+ub)/2;
		}
		assign_path();	
		j++;
	}
	//cout<<"Num"<<num_of_paths;
}


void preprocess()
{
	for(int i=0;i<num_of_variables;i++) 
	test[i]=test_case[0][i];
	find_path();
	assign_fitness();
	fitness[num_of_paths] = find_fitness(0);
	num_of_paths++;
//	num_of_test_cases++;
	fit_access++;
	more_test_cases();	
}

int find_new_node()
{
	int i=0,fit=0;
	while(temp_path1[i]!=-1)
	{
		if(nodes_covered[temp_path1[i]]!=1)
		{
			fit++;
			nodes_covered[temp_path1[i]]=1;
		}
		i++;
	}
	return fit;
}



void generateTestCase()
{
	iterations++;
	int i,j,k;
	double r;
	if(num_of_paths==1)
	{
		//cout<<"Here";
		srand(time(NULL));
		for(int i=0;i<num_of_variables;i++)
		{
		double scaled = (double)rand()/RAND_MAX;
		test[i]= test[i]*scaled;
		if(test[i]>ub)
		test[i]=ub;
		if(test[i]<lb)
		test[i]=lb;
		//cout<<test[i]<<" ";
		}
		find_path();
				int i;
				int new_node = find_new_node();
				if(new_node>0)
				{	
					i=0;
					significant_path_count++;
					while(temp_path1[i]!=-1)
					{
						path[num_of_paths][i]=temp_path1[i];
						i++;
					}
					for(i=0;i<num_of_variables;i++)
					{
						test_case[num_of_paths][i] = test[i];
					}
					int new_fitness = find_fitness(1);
					fit_access++;
					fitness[num_of_paths]=new_fitness;
					num_of_paths++;	
				}
				else
				{
					if(insignificant_path_count<50)
					{
						//insignificant_path_count++;
						k=0;
						while(temp_path1[k]!=-1)
						{	
							red_path[insignificant_path_count][k]=temp_path1[k];
							k++;
						}
							
					
					for(k=0;k<num_of_variables;k++)
					{
						red_test_case[insignificant_path_count][k] = test[k];
					} 
					insignificant_path_count++;
					}
				}
	}
	else
	{
		//cout<<"Paths"<<num_of_paths;
		for(i=0;i<num_of_paths;i++)
	{
		for(j=0;j<num_of_paths;j++)
		{
			srand(time(NULL));
			if(fitness[j]>=fitness[i])
			{
				//cout<<"H2ere\n";
				fit_access++;
				r = (   (double)rand() / ((double)(RAND_MAX)+(double)(1)) );
				for(k=0;k<num_of_variables;k++)
				{
					test[k]=test_case[i][k]+ (test_case[j][k]-test_case[i][k])*(r-0.5)*2;
					if(test[k]<lb)
					test[k]=lb;
					if(test[k]>ub)
					test[k]=ub;
				//	cout<<"Try"<<test[k];	
				}
				//cout<<"\n";
				fitness[i]=fitness[i]+ exp(j-i);
				find_path();
				int new_node = find_new_node();
				if(new_node>0)
				{	
				//	cout<<"Henre";
					i=0;
					significant_path_count++;
					while(temp_path1[i]!=-1)
					{
						path[num_of_paths][i]=temp_path1[i];
						i++;
					}
					for(i=0;i<num_of_variables;i++)
					{
						test_case[num_of_paths][i] = test[i];
					}
					int new_fitness = find_fitness(1);
					fit_access++;
					fitness[num_of_paths]=new_fitness;
					num_of_paths++;	
				}
				else
				{
				//	cout<<"Heire";
					//insignificant_path_count++; 
					if(insignificant_path_count<50)
					{
						//insignificant_path_count++;
						k=0;
						while(temp_path1[k]!=-1)
						{	
							red_path[insignificant_path_count][k]=temp_path1[k];
							k++;
						}
							
					
					for(k=0;k<num_of_variables;k++)
					{
						red_test_case[insignificant_path_count][k] = test[k];
					} 
					insignificant_path_count++;	
				}
				}
			}
		}
	}
	}
	
}

void Print()
{
	int i;
	cout<<"\n\nNon Redundant Test Cases\n";
	for(i=0;i<num_of_paths;i++)
	{
		for(int k=0;k<num_of_variables;k++)
		cout<<test_case[i][k]<<" ";
		cout<<"\tPath\t";
		int j=0;
		while(path[i][j]!=-1)
		{
			cout<<path[i][j]<<" ";
			j++;
		}
		cout<<"\n";
	}
	//cout<<insignificant_path_count;
	cout<<"\n\nRedundant Test Cases\n";
	for(i=0;i<insignificant_path_count;i++)
	{
		for(int k=0;k<num_of_variables;k++)
		cout<<red_test_case[i][k]<<" ";
		cout<<"\tPath\t";
		int j=0;
		while(red_path[i][j]!=-1)
		{
			cout<<red_path[i][j]<<" ";
			j++;
		}
		cout<<"\n";
	}
	
}

void Firefly()
{
	preprocess();
	while(1)
	{
		iterations++;
		//cout<<"Here";
		generateTestCase();
		int num_covered = 0;
		for(int i=0;i<num_lines;i++)
		{
			if(nodes_covered[i]==1)
			num_covered++;	
		}
		if(num_covered>(0.9*num_lines))
		break;
	}
}

int main()
{
	clock_t t;
 	t = clock();
	introMsg();
	Firefly();
	Print();
	double time_taken = ((double)t);
 	cout<<"\nAverage time taken per iteration per CPU clock cycle = "<<time_taken;
 	cout<<"\nNumber of iterations = "<<iterations+5;
 	cout<<"\nNumber of Fitness accesses = "<<fit_access;
 	
	return 0;
}
