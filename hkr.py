st=input()
# st1=st[-1::-1]
count=0
# print(st)
while 'ab' in st:
    st=st.replace('ab','bba')
    count+=1
    print(st)
print(count)