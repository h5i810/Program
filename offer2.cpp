/*************************************************************************
* 题目：请实现一个函数，啊字符串中的每个空格都替换为“%20”，例如，输入
*       “We are happy.”，则输出“We%20are%20happy.”
************************************************************************/

void replaceSpace(char *str, int length){
    if(str==NULL || length<=0)
        return;
    int oldnumber=0;
    int replacenumber=0;

    while(str[i]!='\0'){
        oldnumber++;
        if(str[i]==' ')
            replacenumber++;
        i++;
    }

    int newlength=oldnumber+replaceSpace*2;
    if(newlength>length)
        return;
    int pOldlength=oldnumber;
    int pNewlength=newlength;

    while(pOldlength>=0&&pNewlength>pOldlength){
        if(str[pOldlength==' '])
        {
            str[pNewlength--]='0';
            str[pNewlength--]='2';
            str[pNewlength--]='%';
        }
        else{
            str[pNewlength--]=str[pOldlength];
        }
        pOldlength--;
    }
}
