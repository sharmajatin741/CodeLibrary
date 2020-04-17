template<typename T>
struct matrix{

	vector<vector<T>> A;
	int r,c;
	matrix(int r=0,int c=0,const T &val=0)
	{
		this-> r = r;
		this-> c = c;
		A.resize(r,vector<T>(c,val));
	}
	matrix operator * (const matrix<T> &B)
	{
		assert(c==B.r);
		matrix<T> C(r,B.c,0);
		for(int i=0;i<r;i++)
			for(int j=0;j<B.c;j++)
				for(int k=0;k<c;k++)
				{
					T res=A[i][k]*B[k][j];
		               #ifdef MOD
						res%=MOD;
					#endif 
					C[i][j]=C[i][j]+res;
					#ifdef MOD
						C[i][j]%=MOD;
					#endif
				}
		return C;
	}
	void operator *= (const matrix<T> &B)
	{
		assert(c==B.r);
		matrix<T> C(r,B.c,0);
		for(int i=0;i<r;i++)
			for(int j=0;j<B.c;j++)
				for(int k=0;k<c;k++)
				{
					T res=A[i][k]*B[k][j];
					#ifdef MOD
						res%=MOD;
					#endif 
					C[i][j]=C[i][j]+res;
					#ifdef MOD
						C[i][j]%=MOD;
					#endif
				}
		this->r=C.r;
		this->c=C.c;
		this->A=C.A;
	}
	matrix operator + (const matrix<T> &B)
	{
		assert(r==B.r&&c==B.c);
		matrix<T> C(r,c,0);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				C[i][j]=A[i][j]+B[i][j];
				#ifdef MOD
					C[i][j]%=MOD;
				#endif
			}
		}
		return C;
	}
	void operator += (const matrix<T> &B)
	{
		assert(r==B.r&&c==B.c);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				A[i][j]=A[i][j]+B[i][j];
				#ifdef MOD
					A[i][j]%=MOD;
				#endif
			}
		}
	}
	matrix operator - (const matrix<T> &B)
	{
		assert(r==B.r&&c==B.c);
		matrix<T> C(r,c,0);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				C[i][j]=A[i][j]-B[i][j];
				#ifdef MOD
					C[i][j]=(C[i][j]+MOD)%MOD;
				#endif
			}
		}
		return C;
	}
	void operator -= (const matrix<T> &B)
	{
		assert(r==B.r&&c==B.c);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				A[i][j]=A[i][j]-B[i][j];
				#ifdef MOD
					A[i][j]=(A[i][j]+MOD)%MOD;
				#endif
			}
		}
	}
	matrix operator - ()
	{
		matrix<T> C(r,c,0);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				C[i][j]=-A[i][j];
				#ifdef MOD
					C[i][j]=(C[i][j]+MOD)%MOD;
				#endif
			}
		}
		return C;
	}
	matrix operator ^ (long long n)
	{
		assert(r==c);
		matrix<T> C(r,r,0);
		matrix<T> X(r,r,0);
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) X[i][j]=A[i][j],C[i][i]=1;
		while(n)
		{
			if(n&1)
				C*=X;
			X*=X;
			n>>=1LL;
		}
		return C;
	}
	void operator ^= (long long n)
	{
		assert(r==c);
		matrix<T> C(r,r,0);
		matrix<T> X(r,r,0);
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) X[i][j]=A[i][j],C[i][i]=1;
		while(n)
		{
			if(n&1)
				C*=X;
			X*=X;
			n>>=1LL;
		}
		this->A=C.A;
	}

	vector<T>& operator [] (int i)
	{
		assert(i<r);
		assert(i>=0);
		return A[i];
	}
	const vector<T>& operator [] (int i) const
	{
		assert(i<r);
		assert(i>=0);
		return A[i];
	}

	friend ostream& operator << (ostream &out,const matrix<T> &M)
	{
		for(int i=0;i<M.r;i++)
		{
			for(int j=0;j<M.c;j++)
			{
				cout<<M[i][j]<<" ";
			}
			cout<<"\n";
		}
		return out;
	}

};
