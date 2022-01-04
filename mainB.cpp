#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <fstream>
#include <tgmath.h>

using namespace std;

struct catData
{
    
    double cuddleScore;
     //temp used in sorting
    string catName; // dynamic array between 3 and 10 letters long
    string tempName;
    

    //constructor
    catData()
    {
        cuddleScore =0.0;
        
        catName =" ";
        tempName =" ";
        
    }

};
struct cafeType
{
    int id; //use an array then make each element random number 
    int tempID; //used for sorting

    //name needs to be dynamic string array 
    //size will be determined by random generator
    string name;
    string t;

    double sales;
    double tempSales;

    int roundedSales;
    int tempRounded;
    catData *cats;
    
    //catData *tempCat;
    //catData *catsTwo;

    

    

    int numCats;
    int tempcat;

    char symbol; 
    

    bool fame;

    double averageCuddles;
    double tempCuddles;
    double sum;

    int month[30];
    double dailySales[30];

    //constructor 
    cafeType()
    {
        id = 0; //use an array then make each element random number 
        tempID=0; //used for sorting

    //name needs to be dynamic string array 
    //size will be determined by random generator
         name =  " ";
         t = " ";

        sales=0.0;
        tempSales=0.0;

        roundedSales=0;
        tempRounded=0;
        
        
        numCats=0;
        tempcat=0;

        symbol =' '; 
        fame =0;

        averageCuddles=0.0;
        tempCuddles=0.0;
        sum=0.0;

        for(int i=0; i<30;i++)
        {
            month[i]=0;
            dailySales[i]=0.0;
        }

    }
  

};

void read(cafeType cafe[], int cafeSize);
void read(cafeType cafe[], int cafeSize)
{
    ifstream in;
    in.open("kittyCafesA.txt");

    for(int i=0; i<cafeSize; i++)
    {
        in>>cafe[i].id;
        
        //cout<<cafe[i].id;
        char symbol;
        in>>symbol;        
        getline(in,cafe[i].name, ':'); //in file pointer, data type read into, delimeter 
        
        //cout<<cafe[i].name;
        
        
        in>>cafe[i].sales;
        //cout<<cafe[i].sales;
        
        in>>symbol;
        in>>cafe[i].numCats;
        //cout<<cafe[i].numCats;
        
        in>>symbol;
        in>>cafe[i].fame;
        in>>symbol;
        
        //cout<<cafe[i].fame;
        

        //create dynamic array for cats to store cat data into based on num cats
        cafe[i].cats = new catData[cafe[i].numCats];
        

        
        
        

        for(int j=0; j<cafe[i].numCats;j++) //works
        {
            in>>cafe[i].cats[j].catName;
            in>>cafe[i].cats[j].cuddleScore;
            

            //cout<<cafe[i].cats[j].catName<<"  "<<cafe[i].cats[j].cuddleScore<<endl;
        }
        
        //exit(1);
        
        
    }
        
}
void getAverageCuddles(cafeType cafe[], int cafeSize);
void getAverageCuddles(cafeType cafe[], int cafeSize)
{
    for(int i=0; i<cafeSize; i++)
    {
        for(int j=0; j<cafe[i].numCats-1; j++)
        {
            
            //cout<<cafe[i].cats[j].cuddleScore<<"   "<<cafe[i].cats[j].catName<<endl;
            cafe[i].sum += cafe[i].cats[j].cuddleScore;
            //cout<<cafe[i].cats[j].cuddleScore<<endl;
            
        

            //calculate average cuddle in each cafe
            //cout<<"\n"<<cafe[i].sum<<endl;

            //average works
            cafe[i].averageCuddles = cafe[i].sum / cafe[i].numCats;
            
        }

        //exit(1);
    }
}

void roundSales(cafeType cafe[], int cafeSize);//works
void roundSales(cafeType cafe[], int cafeSize)
{
    for(int i=0; i<cafeSize; i++)
    {
        //round all sales to nearest 1000
        
        
        cafe[i].roundedSales = round(cafe[i].sales/1000.0);
        cafe[i].roundedSales = int (cafe[i].roundedSales*1000);
        
        //cout<<cafe[i].roundedSales<<endl;
       
    }

}

void sortSales(cafeType cafe[], int cafeSize);
void sortSales(cafeType cafe[], int cafeSize)
{
    //sort first by highest sales
    //if sales are equal then sort by highest average cuddle
    //if average cuddles same then sort by highest amount of cats

    catData *tempCat;
    
   
    
    for(int i=0; i<cafeSize; i++)
    {
        tempCat = new catData[cafe[i].numCats];
        
        
        for(int j=i+1; j<cafeSize; j++)
        {
            if(cafe[i].roundedSales == cafe[j].roundedSales)
            {
               if(cafe[i].averageCuddles == cafe[j].averageCuddles)
               {
                   if(cafe[i].numCats< cafe[j].numCats)
                    {
                        cafe[i].t = cafe[i].name;
                        cafe[i].name = cafe[j].name;
                        cafe[j].name = cafe[i].t;

                        cafe[i].tempcat = cafe[i].numCats;
                        cafe[i].numCats = cafe[j].numCats;
                        cafe[j].numCats = cafe[i].tempcat; 

                        cafe[i].tempID = cafe[i].id;
                        cafe[i].id = cafe[j].id;
                        cafe[j].id = cafe[i].tempID;
                
                        cafe[i].tempSales = cafe[i].sales;
                        cafe[i].sales = cafe[j].sales;
                        cafe[j].sales = cafe[i].tempSales;

                        cafe[i].tempCuddles = cafe[i].averageCuddles;
                        cafe[i].averageCuddles = cafe[j].averageCuddles;
                        cafe[j].averageCuddles = cafe[i].tempCuddles;
                        
                        
                        
                        tempCat = cafe[i].cats;
                        cafe[i].cats = cafe[j].cats;
                        cafe[j].cats = tempCat;
                            
                    }
                }
                
               
               if(cafe[i].averageCuddles < cafe[j].averageCuddles)
                {
                    cafe[i].t = cafe[i].name;
                    cafe[i].name = cafe[j].name;
                    cafe[j].name = cafe[i].t;

                    cafe[i].tempcat = cafe[i].numCats;
                    cafe[i].numCats = cafe[j].numCats;
                    cafe[j].numCats = cafe[i].tempcat; 

                    cafe[i].tempID = cafe[i].id;
                    cafe[i].id = cafe[j].id;
                    cafe[j].id = cafe[i].tempID;
                
                    cafe[i].tempSales = cafe[i].sales;
                    cafe[i].sales = cafe[j].sales;
                    cafe[j].sales = cafe[i].tempSales;

                    cafe[i].tempCuddles = cafe[i].averageCuddles;
                    cafe[i].averageCuddles = cafe[j].averageCuddles;
                    cafe[j].averageCuddles = cafe[i].tempCuddles;

                    
                    tempCat = cafe[i].cats;
                    cafe[i].cats = cafe[j].cats;
                    cafe[j].cats = tempCat;
                    
                     

                    
                }
            }
            if(cafe[i].roundedSales < cafe[j].roundedSales)
            {
                
                cafe[i].tempRounded = cafe[i].roundedSales;
                cafe[i].roundedSales = cafe[j].roundedSales;
                cafe[j].roundedSales = cafe[i].tempRounded;
                
                cafe[i].t = cafe[i].name;
                cafe[i].name = cafe[j].name;
                cafe[j].name = cafe[i].t;

                cafe[i].tempcat = cafe[i].numCats;
                cafe[i].numCats = cafe[j].numCats;
                cafe[j].numCats = cafe[i].tempcat; 

                cafe[i].tempID = cafe[i].id;
                cafe[i].id = cafe[j].id;
                cafe[j].id = cafe[i].tempID;
                
                cafe[i].tempSales = cafe[i].sales;
                cafe[i].sales = cafe[j].sales;
                cafe[j].sales = cafe[i].tempSales;

                cafe[i].tempCuddles = cafe[i].averageCuddles;
                cafe[i].averageCuddles = cafe[j].averageCuddles;
                cafe[j].averageCuddles = cafe[i].tempCuddles;

                
                tempCat = cafe[i].cats;
                cafe[i].cats = cafe[j].cats;
                cafe[j].cats = tempCat;


            }

    
        }
        
    } 
 
    
    
    
}



void print(cafeType cafe[], int cafeSize, ofstream &out);
void print(cafeType cafe[], int cafeSize, ofstream &out)
{
    
    
    
    for(int i=0; i<cafeSize; i++)
    {
        out << left << setw(15) << cafe[i].id
             << right << setw(20) << setfill(' ') << cafe[i].name;
        out<<setprecision(2)<<fixed<<showpoint;
        out<<left<<setw(5)<<setfill(' ')<<' '
             << left <<setw(5) << setfill(' ') << cafe[i].sales;
        out<<setprecision(4)<<showpoint;
        out<<right<<setw(6)<<setfill(' ')<<"   "<<cafe[i].averageCuddles
            <<setw(6)<<setfill(' ')<<" "<<right<<cafe[i].numCats;

        catData lowestCat[1];
        
        lowestCat[0].catName = cafe[i].cats[0].catName;
        lowestCat[0].cuddleScore = cafe[i].cats[0].cuddleScore;

        

        if(cafe[i].fame ==1 && (cafe[i].fame == true))
        {
            
            for(int j=0; j<cafe[i].numCats; j++)
            {
                if(lowestCat[0].cuddleScore > cafe[i].cats[j].cuddleScore)
                {
                    lowestCat[0].cuddleScore = cafe[i].cats[j].cuddleScore;
                    lowestCat[0].catName = cafe[i].cats[j].catName;
                }
            }
            out<<setw(6)<<setfill(' ')<<" "<<right<<lowestCat[0].catName;
        }
           
            
        
        out<<endl;


    }
}

void printLowPerformers(cafeType cafe[], int cafeSize, ofstream &out);
void printLowPerformers(cafeType cafe[], int cafeSize, ofstream &out)
{
    out<<"\n\n+++++++++++LOW PERFORMERS+++++++++++"<<endl;
    for(int i=4989; i<cafeSize; i++)
    {
        out << left << setw(15) << cafe[i].id
             << right << setw(20) << setfill(' ') << cafe[i].name;
        out<<setprecision(2)<<fixed<<showpoint;
        out<<left<<setw(5)<<setfill(' ')<<' '
             << right <<setw(5) << setfill(' ') << cafe[i].sales;
        out<<fixed<<setprecision(4)<<showpoint;
        out<<setw(5)<<setfill(' ')<<left<<"   "<< cafe[i].averageCuddles;
        out<<setw(6)<<setfill(' ')<<left<<" "<<cafe[i].numCats;

        catData lowestCat[1];
        //fame print cat name
        lowestCat[0].catName = cafe[i].cats[0].catName;
        lowestCat[0].cuddleScore = cafe[i].cats[0].cuddleScore;

        

        if(cafe[i].fame ==1 && (cafe[i].fame == true))
        {
            
            for(int j=0; j<cafe[i].numCats; j++)
            {
                if(lowestCat[0].cuddleScore > cafe[i].cats[j].cuddleScore)
                {
                    lowestCat[0].cuddleScore = cafe[i].cats[j].cuddleScore;
                    lowestCat[0].catName = cafe[i].cats[j].catName;
                }
            }
            out<<setw(6)<<setfill(' ')<<" "<<right<<lowestCat[0].catName;
        }
        out<<endl;
    }
}

void printReport(cafeType cafe[], int cafeSize,ofstream &out);
void printReport(cafeType cafe[], int cafeSize, ofstream &out)
{
    //mean monthly sales //total sales
    double totalSales =0;
    for(int i=0; i<cafeSize; i++)
    {
        totalSales += cafe[i].sales;
    }
    double meanSales = totalSales /5000;
    //average cats at each shop
    //total cats at company
    //mean cuddles company wide
    //total famous cats 
    int averageCats;
    int totalCats;
    double totalCuddles;
    double meanCuddles;
    int totalFamousCats=0; 
    for(int i=0; i<cafeSize; i++)
    {
        totalCats += cafe[i].numCats;
        totalCuddles += cafe[i].averageCuddles;
        
        for(int j=0; j<cafe[i].numCats; j++)
        {
            if(cafe[i].cats[j].cuddleScore <= 3) //if cat has score <=3 they are famous cat 
            {
                totalFamousCats +=1;
            }
        }
        

    }
    averageCats = totalCats/5000;
    meanCuddles = totalCuddles /5000;

    out<<"\n\n++++++++ REPORT +++++++++"<<endl
        <<"Total Cats: "<<totalCats<<endl
        <<"Cats/Cafe: "<<averageCats<<endl;
    out<<setprecision(2)<<fixed<<showpoint;
    out<<"Total Sales: "<<totalSales<<endl
        <<"Sales/Cafe: "<<meanSales<<endl;
    out<<"Cuddles/Cafe: "<<meanCuddles<<endl
        <<"Total Famous Cats: "<<totalFamousCats<<endl;

}



int main()
{
    ofstream out;
    out.open("results.txt");

    int cafeSize =5000;
    
    cafeType *cafe;
    cafe = new cafeType[5000];
    

    read(cafe,cafeSize);
    getAverageCuddles(cafe, cafeSize);
    roundSales(cafe, cafeSize);
    sortSales(cafe, cafeSize);
    


    print(cafe, cafeSize,out);
    printLowPerformers(cafe, cafeSize, out);
    printReport(cafe, cafeSize,out);

    

    
    

    return 0;
}
