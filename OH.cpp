#include <iostream>
using namespace std;
struct HNode
{
    HNode *next;
    int key;
    HNode(int x)
    {
        key = x;
        next = NULL;
    }
};
void insertValue(int x, HNode *HT[], int HS)
{
    int HI;
    HI = x % HS;
    if (HT[HI] == NULL)
    {
        HT[HI] = new HNode(x);
    }
    else
    {
        struct HNode *temp = new HNode(x);
        struct HNode *th;
        th = HT[HI];
        HT[HI]=temp;
        HT[HI]->next = th;
    }
}
bool searchInHT(struct HNode *HT[], int HS, int x)
{
    int HI;
    HI = x % HS;
    if (HT[HI]!=NULL && HT[HI]->key == x)
    {
        return true;
    }
    else if(HT[HI]!=NULL && HT[HI]->next != NULL)
    {
        struct HNode *th = HT[HI];
        while (th->next != NULL)
        {
            if (th->next->key == x)
            {
                return true;
                break;
            }
            th = th->next;
        }
    }
    else
    {
        return false;
    }
}
void printHT(HNode *HT[], int HS)
{
    cout << "The Hashing table is : ";
    for (int i = 0; i < HS; i++)
    {
        if (HT[i] == NULL)
        {
            cout << endl;
            cout << "[-]";
        }
        if (HT[i] != NULL)
        {
            cout << endl;
            cout << "[" << HT[i]->key << "]";
            HNode *n = HT[i];
            while (n->next != NULL)
            {
                cout << "<--"
                     << "[" << n->next->key << "]";
                n = n->next;
            }
        }
    }
    cout << endl;
}
int main()
{
    int HS;
    cout << "Enter the Size of Hash Table :";
    cin >> HS;
    //struct HNode *HT[HS];
    struct HNode **HT = new HNode*[HS];
    for (int i = 0; i < HS; i++)
    {
        HT[i] = NULL;
    }
    cout<<endl;
    cout<<endl;
    int option,x,s;
        do
    {
        cout<<"What operations do you want to perform?Select Option Number.Enter 0 to exit."<<endl;
        cout<<"1. insertValue"<<endl;
        cout<<"2. print Hash Table"<<endl;
        cout<<"3. search In Hash Table"<<endl;
        cout<<"4. Clear Screen"<<endl;
        cin>>option;
        switch (option)
        {
        case 0:
            cout<<"Thanks !!"<<endl;
            break;
        case 1:
            cout<<"Enter the data you want to insert"<<endl;
            cin>>x;
            insertValue(x,HT,HS);
            break;
        case 2:
            printHT(HT,HS);
            break;
        case 3:
            cout<<"Enter the key that you want to search in Hash table :";
            cin>>s;
            cout<<endl;
            bool res;
            res = searchInHT(HT,HS,s);
            if(res == true){
                cout << s << " key has been located in the Hash table!!!" << endl;
                cout<<endl;
            }
            else{
                cout << s << " key is not present in the Hash table!!!" << endl;
                cout<<endl;
            }
            break;
        case 4:
            system("cls");
            break;
        default:
            cout<<"Enter proper option Number "<<endl;
        }
    } while (option !=0);
    delete(HT);
    return 0;
}
