#include "generation.h"
#include "ui_generation.h"
#include"mainwindow.h"
int biggestfactor(int a,int b);
int ExtendedEuclid(int f,int d);

int chartonumber(char plaintext[],int plainnumber[],int n);
Generation::Generation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Generation)
{
    ui->setupUi(this);
    /*ui->label->setVisible(false);

    ui->lineEdit->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->lineEdit_4->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->pushButton_3->setVisible(false);*/

    ui->nnnnn->setVisible(false);
}

Generation::~Generation()
{
    delete ui;
}
QString Generation::GetLineedit_1()
{
    return ui->lineEdit_3->text();
}
QString Generation::GetLineedit_2()
{
    return ui->lineEdit_4->text();
}
QString Generation::GetLineedit_3()
{
    return ui->nnnnn->text();
}
void Generation::on_pushButton_clicked()
{
    accept();
}

void Generation::on_radioButton_clicked()
{
    ui->label->setVisible(true);
    ui->lineEdit->setVisible(true);
    ui->lineEdit_2->setVisible(true);
    ui->lineEdit_3->setVisible(true);
    ui->lineEdit_4->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->pushButton_3->setVisible(true);
}

void Generation::on_pushButton_3_clicked()
{
    int i;
    int p=ui->lineEdit->text().toInt();
    int q=ui->lineEdit_2->text().toInt();
    int yn=(p-1)*(q-1);
    int biggest;
    int d=0;
    int e=0;
    int n=q*p;
    ui->nnnnn->setText(QString::number(n));
    for(i=(yn/3);i<yn;i++){
            biggest=biggestfactor(i,yn);       //互质的数
            if(biggest==1){
                d=i;
                printf("d is:%d\n",d);
                e=ExtendedEuclid(d,yn);              //求出逆元
                if(e<0){
                    e=e+yn;}
                printf("e is:%d\n",e);
                break;}
        }
    ui->lineEdit_3->setText(QString::number(e));
    ui->lineEdit_4->setText(QString::number(d));


}
int biggestfactor(int a,int b){
    int remainder=b%a;
    while(remainder!=0){
        b=a;
        a=remainder;
        remainder=b%a;
    }
    return a;
}
int ExtendedEuclid(int f,int d){              //求逆元
    int x1,x2,x3,y1,y2,y3,t1,t2,t3,q;
    x1=y2=1;
    x2=y1=0;
    x3=(f>=d)?f:d;
    y3=(f>=d)?d:f;
    while(1)
    {
        if (y3==0)
        {
            return 0;}
        if(y3==1)
        {
            return y2;}
        q=x3/y3;
        t1=x1-q*y1;
        t2=x2-q*y2;
        t3=x3-q*y3;
        x1=y1;
        x2=y2;
        x3=y3;
        y1=t1;
        y2=t2;
        y3=t3;}
}
int chartonumber(char plaintext[],int plainnumber[],int n){
    int block=-1;
    int length=strlen(plaintext);
    int i,j;
    while(n!=0){
        n=n/2;
        block++;
    }

    for(j=0;j<length;j++){
        for(i=1;i<=8;i++){
            plainnumber[8*j-i+8]=plaintext[j]%2;
            plaintext[j]=plaintext[j]/2;
        }
    }

    for(i=0;i<length*8;i++){
            printf("%d",plainnumber[i]);}

    printf("\n");
       return block;
}
