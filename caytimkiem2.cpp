#include<stdio.h>
#include<math.h>
typedef struct Node{
    int data;
    Node *pLeft,*pRight;
};
typedef Node* Tree;
Tree root;
Node *TaoNode(int x);
void ThemNodeVaoCay(Node *p,Tree &c);
void Nhap(Tree &c);
void Xuat(Tree c);
Node *TimKiemNode(Tree c,int x);
int Them(Tree &c ,int x);
void searchStandFor(Tree &p,Tree &q);
int delNode(Tree &c,int x);
int DemNode(Tree c);
int DemNodeLa(Tree c);
int ChieuCao(Tree c);
int TinhTongCacNutChan(Tree c);
int TimSoChinhPhuong(Tree c);
void XuatsoChan(Tree c);
int TinhTongCacNut1Con(Tree c);
int main(){
    Tree c = NULL;
    Nhap(c);
    printf("\nXuat Cay :");
    Xuat(c);
    if(TimSoChinhPhuong(c)==0)
        printf("\nKhong co");
    else
        printf("\nSo Luong so chinh phuong:%d",TimSoChinhPhuong(c));
    XuatsoChan(c);    
    return 0;
}
Node *TaoNode(int x){
    Node *p = new Node;
    if(p==NULL)
        return NULL;
    p->data = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;   
}
void ThemNodeVaoCay(Node *p,Tree &c){
    if(c==NULL)
        c=p;
    else{
        if(p->data<c->data)
            ThemNodeVaoCay(p,c->pLeft);
        else if(p->data>c->data)
            ThemNodeVaoCay(p,c->pRight);
        else
            return;        
    }    
}
void Nhap(Tree &c){
    int x;
    printf("Nhap vao du lieu,-1 de ket thuc\n");
    do{
        scanf("%d",&x);
        if(x!=-1)
            ThemNodeVaoCay(TaoNode(x),c);
    }while(x!=-1);
}
void Xuat(Tree c){
    if(c!=NULL){
        Xuat(c->pLeft);
        printf("\n%d",c->data);
        Xuat(c->pRight);
    }
}
void scp(Tree c){
    int dem = 0;
    while(c->data==-1){
        if(c->data = sqrt(c->data)*sqrt(c->data))
            dem++;
        c=c->pLeft;
        c=c->pRight;    
    }
    printf("\nSo luong so chinh phuong:%d",dem);
}
Node *TimKiemNode(Tree c,int x){
    if(c){
        if(c->data==x)
            return c;
        if(c->data>x)
            return TimKiemNode(c->pLeft,x);
        return TimKiemNode(c->pRight,x);        
    }
    return NULL;
}
int Them(Tree &c ,int x){
    if(c){
        if(c->data==x)
            return 0;
        if(c->data>x)
            return Them(c->pLeft,x);
        return Them(c->pRight,x);    
        }
        c = new Node;
        if(c==NULL) return -1;
        c->data=x;
        c->pLeft=c->pRight=NULL;
        return 1;   
}
void searchStandFor(Tree &p,Tree &q){
    if(q->pLeft)
        searchStandFor(p,q->pLeft);
    else{
        p->data=q->data;
        p=q;
        q=q->pRight;
    }    
}
int delNode(Tree &c,int x){
    if(c==NULL) return 0;
    if(c->data>x) return delNode(c->pLeft,x);
    if(c->data<x) return delNode(c->pRight,x);
    Node *p =c;
    if(c->pLeft==NULL)
        c=c->pRight;
    else
        if(c->pRight==NULL) c=c->pLeft;
        else
            searchStandFor(p,c->pRight);
    delete p;        
}
int DemNode(Tree c){
    if(c==NULL)
        return 0;
    return (1+ DemNode(c->pLeft) + DemNode(c->pRight));    
}
int DemNodeLa(Tree c){
    if(c==NULL)
        return 0;
    else{
        if(c->pLeft==NULL && c->pRight==NULL)
            return 1;
        else
            return (DemNodeLa(c->pLeft) + DemNodeLa(c->pRight));    
    }    
}
int ChieuCao(Tree c){
    if(c==NULL)
        return 0;
    else{
        if(ChieuCao(c->pLeft)>ChieuCao(c->pRight))
            return ChieuCao(c->pLeft);
        return ChieuCao(c->pRight);    
    }    
}
int TinhTongCacNutChan(Tree c)
{
    if(c==NULL)
        return 0;
    else
    {
        int tongTrai = TinhTongCacNutChan( c->pLeft );
        int tongPhai = TinhTongCacNutChan( c->pRight);
        if( c->data % 2 == 0 )
            return c->data + tongTrai + tongPhai;
        else
            return tongTrai + tongPhai;
    }
}
int TimSoChinhPhuong(Tree c)
{
    if(c ==NULL)
        return 0;
    else
    {
        int soNutChanTrai = TimSoChinhPhuong( c->pLeft );
        int soNutChanPhai = TimSoChinhPhuong( c->pRight );
        if( c->data == sqrt(c->data)*sqrt(c->data))
            return 1 + soNutChanTrai + soNutChanPhai;
        else
            return soNutChanTrai + soNutChanPhai;
    }
}
void XuatsoChan(Tree c){
    if(c!=NULL){
        if(c->pLeft!=NULL)
            XuatsoChan(c->pLeft);
        if(c->data%2==0)
            printf("\nSo phan tu chan:%d",c->data);
        if(c->pRight!=NULL)
            XuatsoChan(c->pRight);        
    }
}
int TinhTongCacNut1Con(Tree c)
{
    if(c==NULL)
        return 0;
    else
    {
        int tongTrai = TinhTongCacNut1Con( c->pLeft );
        int tongPhai = TinhTongCacNut1Con( c->pRight);
        if( (c->pLeft==NULL && c->pRight!=NULL) || (c->pLeft!=NULL && c->pRight==NULL) )
            return c->data + tongTrai + tongPhai;
        else
            return tongTrai + tongPhai;
    }
}
