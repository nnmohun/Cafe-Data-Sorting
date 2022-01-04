#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <fstream>

using namespace std;

struct catData
{
    
    double cuddleScore;
    char *catName; // dynamic array between 3 and 10 letters long

};
struct cafeType
{
    int id; //use an array then make each element random number 
    int temp; //used for sorting

    //name needs to be dynamic string array 
    //size will be determined by random generator
    char *name;
    char nameSize;

    double sales;

    catData *cats;

    int numCats;
    

    bool fame;

    double averageCuddles;
    double sum;

    int month[30];
    double dailySales[30];

};

void sortID(cafeType cafe[], int cafeSize);
void sortID(cafeType cafe[], int cafeSize)
{
    //temp cafe id array
    cafeType *temp;
    temp = new cafeType[5000];

    
    
    //sorting array of ids in asceding order
    for(int i=0; i<cafeSize; i++)
    {
        for(int j=i+1; j<cafeSize; j++)
        {
            //for(int k=0; k<8; k++)
            //{
                if(cafe[i].id>cafe[j].id)
                {
                    temp[i]=cafe[i];
                    cafe[i]=cafe[j];
                    cafe[j]=temp[i];
                    
                    /*cafe[i].temp = cafe[i].id;
                    cafe[i].id = cafe[j].id;
                    cafe[j].id = cafe[i].temp;*/
                }
            //}
        }
        //cout<<cafe[i].id<<endl;
    }
  
    
}
void getSalesData(cafeType cafe[], int cafeSize); //works
void getSalesData(cafeType cafe[], int cafeSize)
{
   //each cafe has 30 days of sales with random num 50 -500 assigned to it
   for(int i=0; i<cafeSize; i++)
   {
       for(int j=0; j<30; j++)
       {
           //get random num assigned to day of the month for the cafe i
           cafe[i].month[j] = rand()%450 +50;
           //cout<<cafe[i].month[j]<<endl;

           setprecision(2);
           //each day of the month multiplies a random num 50-500 * average cuddle score
           cafe[i].dailySales[j] = (cafe[i].month[j] * (cafe[i].averageCuddles));
           //cout<<cafe[i].dailySales[j]<<endl;

           //if that cafe has a famous cat that day sales multiplied by .5
           if(cafe[i].fame == 1)
           {
               //cout<<"fame found, increasing sales now"<<endl; 
               double increase = (cafe[i].dailySales[j] * .5);
               cafe[i].dailySales[j] += increase; 
               //cout<<cafe[i].dailySales[j]<<endl;
           }
           //sum all days of the monthly sales
           cafe[i].sales += cafe[i].dailySales[j];
        

       }
       
       //cout<<"monthly sales: "<<cafe[i].sales<<endl;
   }
   
   
   

}

void getAverageCuddleScore(cafeType cafe[], int cafeSize);
void getAverageCuddleScore(cafeType cafe[], int cafeSize)
{
    for(int i=0; i<cafeSize; i++)
    {
        for(int j=0; j<cafe[i].numCats; j++)
        {
            cafe[i].sum += cafe[i].cats[j].cuddleScore;
            
        

            //calculate average cuddle in each cafe
            //cout<<"\n"<<cafe[i].sum<<endl;

            //average works
            cafe[i].averageCuddles = cafe[i].sum / cafe[i].numCats;
            
        }
    }
}



void setCatCuddleScore(cafeType cafe[], int cafeSize); //works for cuddle score
void setCatCuddleScore(cafeType cafe[], int cafeSize)
{
    //make the cuddle score randomized double 1-20 
    for(int i=0; i<cafeSize; i++)
    {
        for(int j=0; j< cafe[i].numCats; j++)
        {
            cout<<setprecision(4)<<fixed<<showpoint;
            double randomCuddle = (double)rand()/RAND_MAX;
            cafe[i].cats[j].cuddleScore = randomCuddle*(20-1) + 1;

              //determine fame by bool =0 or bool =1 for fame
            if(cafe[i].cats[j].cuddleScore <= 3.0000)
                cafe[i].fame = 1;//true fame exists
            else
                cafe[i].fame =0; //false no fame
            
            
        }
    }
}
void setCatNameData(cafeType cafe[], int cafeSize); //works for cat name
void setCatNameData(cafeType cafe[], int cafeSize)
{
    //random cat number between 8 and 20 also sets size of cats array
    for(int i=0; i<cafeSize;i++)
    {
        cafe[i].numCats = (rand()%13) +8; //random cat number 
        int catNum = cafe[i].numCats;

        //create dynamic cats array of the number of cats
        cafe[i].cats = new catData[catNum];
        //cout<<"\nThis cafe has "<<cafe[i].numCats<<" cats"<<endl;
        
        
        //make each name and score for the cat data
        for(int j=0; j<catNum; j++)
        {
            //create cat name array size 3-10 elements randomly
            int name;
            name = (rand()%8) + 3;

            //dynamic array of cat name from random name size above
            cafe[i].cats[j].catName = new char[name];
            for(int k=0; k<name; k++)
            {
                //fill the cat name with random letters
                char r = rand()%26; //generate random letter
                char letter = 'a'+r;
                
                cafe[i].cats[j].catName[k]= letter;
            }
            
        }
    
    }
    
    
}







void setID(cafeType cafe[], int cafeSize);
void setID(cafeType cafe[], int cafeSize) //not sure if unique is achieved here 
{
    //using random number to make random num 
    srand(time(NULL));
    int same =0; 

    cafeType *tempId;
    tempId = new cafeType[5000]; //temp ID to see if ids are the same
    for(int i=0; i<cafeSize; i++)
    {
        cafe[i].id = (rand()%33000) +10000000;
        tempId[i].id = (rand()%33000)+10000000;
        //cout<<cafe[i].id<<endl;
        //for(int j=i; j<cafeSize; j++)
        //{
            while(cafe[i].id == cafe[i-1].id)
            {
                //new random for cafe id 
                //cout<<"found same id"<<endl;
                same +=1;
                int newRand = (rand()%40000) +10000000;
                cafe[i].id = newRand;
                
            }
        //}
        
    }
    


   
}

void setName(cafeType cafe[], int cafeSize); //works
void setName(cafeType cafe[], int cafeSize)
{
    //get size of char random array for the word of cafe
    //each random number will be created in new loop of data for struct array 
    int charSize;
    for(int i=0; i<cafeSize; i++)
    {
        charSize = (rand() %15)+1;
        cafe[i].nameSize = charSize;
        //cout<<charSize<<endl;
        //make char array for the name using dynamic array
        cafe[i].name = new char[charSize];
        for(int j =0; j<charSize; j++)
        {
            char r = rand()%26; //generate random letter
            char letter = 'a'+r;
            cafe[i].name[j] = letter; //fill cafe name with random letter
            
        }
    }
    
    
    
}

//print test works
void print(cafeType cafe[], int cafeSize);
void print(cafeType cafe[], int cafeSize)
{
    ofstream out;
    out.open("kittycafesA.txt");

    for(int i=0; i<cafeSize; i++)
    {
        out<<cafe[i].id<<":";
        for(int j=0; j<cafe[i].nameSize; j++)
        {
            out<<cafe[i].name[j];
            
        }
        out<<" Cafe:";
        out<<setprecision(2)<<fixed<<showpoint;
        out<<cafe[i].sales<<":"<<cafe[i].numCats<<":"<<cafe[i].fame<<":";
        for(int j=0; j< cafe[i].numCats; j++)
        {
            out<<setprecision(4);
            out<<cafe[i].cats[j].catName<<" "<<cafe[i].cats[j].cuddleScore<<" ";
        }
        out<<endl;
        
    }
    out.close();
}

int main()
{

    int cafeSize =5000;
    cafeType *cafe;
    cafe = new cafeType[5000]; //array of structs 
    catData *cats;


    setID(cafe, cafeSize);
    sortID(cafe, cafeSize);
    setName(cafe, cafeSize);
    
    setCatNameData(cafe, cafeSize);
    setCatCuddleScore(cafe, cafeSize);
    getAverageCuddleScore(cafe, cafeSize);
    getSalesData(cafe, cafeSize);
    
    print(cafe, cafeSize);

    
   
    
    
        

    return 0;
}