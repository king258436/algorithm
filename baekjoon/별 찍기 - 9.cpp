#include<iostream>
#include<cstdio>
using namespace std;
 
class star{
private:
    int n;
    void draw(int key, bool isStar) const;
    void printStar(bool a) const;
public:
    star(int n):n(n){}
 
    void callDraw(bool diamond) const{
        for(int i=0; i<n-1; i++){
            this->draw(i, diamond);    //위
        }
        for(int i=0; i<n; i++){
            this->draw(n-i-1, diamond);  //아래
        }
    }
 
};
void star::draw(int key, bool isStar) const{
    for(int i=0; i<key; i++) printStar(isStar);
    for(int j=0; j<(2*n)-(2*key)-1; j++) printStar(!isStar);
    //for(int i=0; i<key; i++) printStar(isStar);
    printf("\n");
 
}
void star::printStar(bool a) const{
    if(a) printf(" ");
    else printf("*");
}
 
int main(void){
    int n;
    cin >> n;
    star *s = new star(n);
    s->callDraw(true);
    delete s;
    return 0;
}