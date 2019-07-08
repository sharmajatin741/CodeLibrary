int mpow(int a,int b,int p=MOD)
{
  a=a%p;
  int res=1;
  while(b>0)
  {
    if(b&1) res=(res*a)%p;
    a=(a*a)%p;
    b=b>>1;
  }
 return res%p;
}
