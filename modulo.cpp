int add(int a,int b)
{
      a+=b;
      if(a>=MOD) a-=MOD;
      return a;
}
int sub(int a,int b)
{
      a-=b;
      if(a<0) a+=MOD;
      return a;
}
int mul(int a,int b)
{     
      return ((long long)a*b)%MOD;
}
int rev(int a)
{
	return mpow(a,MOD-2);
}