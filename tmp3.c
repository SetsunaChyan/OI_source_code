void fun3(int x){if(x>7) for(;;);}
void fun2(int x){if(x>1) fun3(x-2);}
void fun1(int x){if(x>0) fun2(x-1);}
int main()
{
    fun1(10);
    return 0;
}

