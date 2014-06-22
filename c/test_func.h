static inline void test()
{
	/*static*/ int a=0;
	printf("%d%p\n",a,&a);
	a++;
}
