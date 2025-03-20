t=int(input())
for i in range(t):
    n,k,MOD=map(int,input().split())
    sum=0
    nums=list(map(int,input().split()))
    for j in range(n):
        sum+=nums[j] 
    z=pow(n,k-1,MOD)
    ans=((sum*z)%MOD*k)%MOD
    tc=i+1
    print("Case "+str(tc)+": "+str(ans))