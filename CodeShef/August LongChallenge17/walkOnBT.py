

t=int(input())
while t>0:
    n, q = map(int, input().split())
    visitCount = 1
    x = 0
    arr = [[0]*2 for i in range(n)]
    prevParent = [[-1]*2 for i in range(n)]
    #arr = [0]*nodes
    #arr = "0"*nodes

    i = 0
    while i < n:
        j = 0
        while j < 2:
            arr[i][j] = 1<<i
            j = j + 1
        i = i + 1


    while q > 0:

        inputs = list(map(str,input().split()))

        if inputs[0] == '!':

            c = int(inputs[1])
            a = 1<<c
            b = 1<<n
            x = (x + a)%b
            #print(x)
            decNo = x
            v = []
            while decNo>0:
                v.append(decNo%2);
                decNo=decNo//2;

            while len(v) < n:
                v.append(0);
            #print(v)
            v.reverse()

            i = 0
            parent = 0
            while i < len(v):
                if v[i] == 0:
                    if prevParent[i][0] == -1:
                        visitCount = visitCount + 1
                        arr[i][0] = arr[i][0] - 1
                        prevParent[i][0] = parent
                    elif arr[i][0] != 0:
                        if prevParent[i][0] == 1 and parent == 0:
                            visitCount = visitCount + 1
                            arr[i][0] = arr[i][0] - 1
                            prevParent[i][0] = 2
                        elif prevParent[i][0] == 0 and parent == 1:
                            visitCount = visitCount + 1
                            arr[i][0] = arr[i][0] - 1
                            prevParent[i][0] = 2
                        elif arr[i][0] == 1<<i:
                            visitCount = visitCount + 1
                            arr[i][0] = arr[i][0] - 1
                            prevParent[i][0] = parent
                    parent = 0
                else:
                    if prevParent[i][1] == -1:
                        visitCount = visitCount + 1
                        arr[i][1] = arr[i][1] - 1
                        prevParent[i][1] = parent
                    elif arr[i][1] != 0:
                        if prevParent[i][1] == 1 and parent == 0:
                            visitCount = visitCount + 1
                            arr[i][1] = arr[i][1] - 1
                            prevParent[i][1] = 2
                        elif prevParent[i][1] == 0 and parent == 1:
                            visitCount = visitCount + 1
                            arr[i][1] = arr[i][1] - 1
                            prevParent[i][1] = 2
                        elif arr[i][1] == 1<<i:
                            visitCount = visitCount + 1
                            arr[i][1] = arr[i][1] - 1
                            prevParent[i][1] = parent
                    parent = 1

                i = i + 1
            v.clear()

        else:
            print(visitCount)
        q = q - 1
        inputs.clear()
    t=t-1





#!/usr/bin/python
s ="1148130695274254524232833201177681984022317702088695200477642736825766261392370313856659486316506269918445964638987462773447118960863055331425931356166653185391299891453122800006887791482400448714289269900634862447816154636463883639473170260404663539709049965581623988089446296056233116495361642219703326813441689089844585056023794848079140589009347765004290027167066258305220081322362812917612678833172065989953964181270217798584040421598531832515408894339020919205549577835896720391600819572166305827553804255837260155283487864194320545089152757838826251754355288008228427708179654537621848511490293"
nodes = 1<<10
x = "0"*nodes
arr = [0]*601
i = 0
while i < 601:
	x = x[:i] + '1' + x[i+1:]
	i = i + 1
print(x)
print(2**2000)
