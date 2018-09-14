//taking the position of the first element at 0th position

#include<string.h>
#include<iostream>
#include<stdlib.h>

class array //class creation
{
    //class member variable and method definition.
    public:
    int *arr, *subarray, size;
    void input(int size);
    void output();
    int insert(int index, int value);
    void del(int index, int value);
    void update(int index, int value);

};

void array::input(int size)     //method to create and initialize the elements
{
    char choise;
    arr = new int[size];
    this->size = size;
    std::cout<<"\nDo you want to insert the elements: y/n -- ";
    std::cin>>choise;
    for(int i =0; i<size; i++)
    {
        std::cout<<"Enter the value of element number "<<i<<" :- ";
        std::cin>>arr[i];
        //std::cout<<std::endl;
    }
}
void array::output()   //method to display the elements of the array
{
    if(arr==0)
    {
        std::cout<<"\nArray is empty.";
    }
    else
    {
        for(int i = 0; i<this->size; i++)
            std::cout<<arr[i]<<"\t";
    }
    std::cout<<std::endl;
}

int array::insert(int index, int value)    //method to insert a element in the array
{                                         //it is not possible to alter the size of the array after creation
    if(index>size+1)                     //so another is created and used that for operation and first one is deleleted 
    {
       std::cout<<"\nInvalid index."<<std::endl;
       return 0;
    }
    else
    {
        int *newarray, *temp;
        newarray = new int[size+1];
        for(int i =0; i<index; i++)
        {
            newarray[i] = arr[i] ;
        }
        newarray[index]=value;
        for(int i =index+1; i<=size+1; i++)
        {
            newarray[i] = arr[i-1];
        }    
    temp = arr;
    arr = newarray;
    size = size+1;   //size of the array become one more with every insertion
    delete []temp;
    delete temp;

    }
    return 1;
}

void array::del(int index, int value=0)  //method to delete an element from the array
{                                       //as it is not possible to alter an array so 
    if(value==0)                        //another one is takes and first one is deleted
    {   }
    else
    {
        int *newarray, *temp, count;
        newarray = new int[size-1];       //if value is provide then first value matching will be deleted
        for(int i=0;i<size;i++)
        {
            if(arr[i]==value)
            {
                int count = i;
                break;
            }
            newarray[i] = arr[i] ;
        }
        for(int i=count; i <size; i++)  
        {
            newarray[i]=arr[i+1];
        }
        temp = arr;
        arr = newarray;
        delete []temp;
        delete temp;
        return;
    }
    int *newarray, *temp, count;  //index is used to delete 
    newarray = new int[size-1];
    for(int i =0; i<index; i++)
    {
        newarray[i] = arr[i] ;
    }    
    for(int i=index+1; i<size; i++)
    {
        newarray[i-1]=arr[i];
    }
    size -= 1;
    temp = arr;
    arr = newarray;
    delete []temp;
    delete temp;
}

void array::update(int index, int value) //taken the index and value and the value is updated
{
    arr[index]=value;
}
int main()
{//main() start
    std::cout<<"its good;\n";
    int choise;
    array a1;
    main_menu: //label to jump at
    //menu creation as main menu
    std::cout<<"########### Menu Options #########"<<std::endl;
    std::cout<<"1. Create Array"<<std::endl; 
    std::cout<<"2. Insert an element"<<std::endl;
    std::cout<<"3. Delete an element"<<std::endl;
    std::cout<<"4. Update an element"<<std::endl;
    std::cout<<"5. Display the elements"<<std::endl;
    std::cout<<"99. Exit."<<std::endl;
    std::cin>>choise;
    switch(choise)
    {
        case 1://creation and initialization
            int size;
            system("clear");
            std::cout<<"What is the size of the array to be created? ";
            std::cin>>size;
            a1.input(size);
            std::cout<<"Array created!!!"<<std::endl;
            goto main_menu;
        case 2://insertion
            int index, value;
            system("clear");
            std::cout<<"Enter the position and value (in order) for the insertion of the element :: ";
            std::cin>>index >> value;
            a1.insert(index, value);
            std::cout<<"Element inserted !!!"<<std::endl;
            goto main_menu;
        case 3://deletion
            system("clear");
            std::cout<<"Enter the position of the element to be deleted.";
            std::cin>>index;
            a1.del(index);
            std::cout<<"Deletion Done!!"<<std::endl;
            goto main_menu;
            
        case 4://updation
            system("clear");
            std::cout<<"Enter the position and new value (in order) to be update";
            std::cin>>index>>value;
            a1.update(index, value);
            std::cout<<"Value updated!!"<<std::endl;
            goto main_menu;
        case 5:
            system("clear");
            a1.output();
            char choise;
            std::cout<<"Press any key to go back.....";
            std::cin>>choise;
            if(toupper(choise)=='Y')
                goto main_menu;
            else
                goto main_menu;

        case 99:
            exit(0);
        default:
            std::cout<<"Invalid option !!!!!"<<std::endl;
            goto main_menu;
    }  //switch case closed  
    return 0;

}//main menu closed