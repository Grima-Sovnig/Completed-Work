#include <iostream>
#include <string>
#include <vector>

#define SIZE 4
#define debug(x) cout<< #x << " = "<< x <<endl
#define swap(typ,A,B) { typ temp;temp=B; B=A;A=temp;}
using namespace std;

vector <int> permset;
string flags;
int mobile_int, mobile_pos;

void vout( vector <int> v)
{
    for(int iter = 0 ; iter < v.size(); iter++ ) 
    {
        cout << v[iter] << " ";
    } 
    cout << endl;
}

void updateFlags()
{
    for(int i=0;i<flags.length();i++)
        if(permset[i]>mobile_int)
            if(flags[i]=='L')
                flags[i]='R';
            else
                flags[i]='L';
}

void swapSets(){
    if(flags[mobile_pos] == 'L' ){
        swap(int, permset[mobile_pos], permset[mobile_pos-1]);
        swap(char, flags[mobile_pos], flags[mobile_pos-1]);
    }
    else{
        swap(int, permset[mobile_pos], permset[mobile_pos+1]);
        swap(char, flags[mobile_pos], flags[mobile_pos+1]);
    }
    updateFlags();
}

void findMobileIntandSwap(){
    mobile_int = 0;
    for(int i=0;i<SIZE;i++){
        if( (flags[i]=='L' && i==0) || (flags[i]=='R' && i == SIZE-1))
            continue;
        if( flags[i] == 'L'){
            if( permset[i] > permset[i-1] && permset[i] > mobile_int ){
                mobile_int = permset[i];
                mobile_pos = i;
            }
        }
        else{
            if( permset[i] > permset[i+1] && permset[i] > mobile_int ){
                mobile_int = permset[i];
                mobile_pos = i;
            }
        }
    }
    swapSets();
}

int fact(int n){
    int x=1;
    for(int i=1; i <= n; i++)
        x *= i;
    return x;
}

int main(){
    for(int i=1;i<=SIZE;i++){
        permset.push_back(i);
        flags.push_back('L');
    }
    int total_permutations = fact(SIZE);
    debug(total_permutations);
    for(int i = 0;i< total_permutations; i++){
        vout(permset);
        findMobileIntandSwap();
    }
    return 0;
}