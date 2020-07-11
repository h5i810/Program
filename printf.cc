
const char digits[] = "0123456789";
size_t PrintintToString(char buf[], int value){
	int num=value;
	char*p=buf;
	if(value==0)
		*p++=digits[0];
		
	while(num){
		int i=num%10;
		*p++ =digits[i];
		num/=10;
	}
	if(value<0){
		*p++="-";
	}
	*p='\0';
	std::reverse(buf, p);
	
	return p-buf;
}


void my_printf(char *val, ...)
{
    int ch;
    va_list arg;
    va_start(arg, val);
    while (*val != '\0')
    {
        switch (*val)
        {
        case '%': //遇到%执行switch case语句
        {
            if (*(val + 1) == 'c') //输出字符
            {
                ch = va_arg(arg, char);
                putchar(ch);
                val++; //指针变量向下偏移一个单位
            }
            else if (*(val + 1) == 'd')
            {
                num = va_arg(arg, int); //输出整形
                cout<< to_string(num);
                val++;
            }
            else if (*(val + 1) == 's') //输出字符串
            {
                char *str = va_arg(arg, char *);
//                while (*p++ != '\0')
//                {
//                    putchar(*p);
//                }
				puts(str);
                val++; //指向头一变量的下一个字符
            }
            else
                putchar('%');
            break;
        }
        default:
        {
            putchar(*val);
            break;
        }
        }
        val++;
    }
    va_end(arg);
}