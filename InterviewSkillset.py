#minimal skillset to an interview in Python

class Skillset:

    def __init__(self):
        self.skill = []

    def __str__(self):
        s= str(len(self.skill)) + "\n"
        for i in range(len(self.skill)):
            s+= str(self.skill[i]) + "\n"

        return s

class Interview(Skillset):

     def __init__(self):
         self.skill = ["Interview"]

     def Add(self, sk):
         self.skill += [sk]

     def GetFreqSkill(self, num):
         self.freqL = [0]*26
         self.freqU = [0]*26
         for l in self.skill[num]:
             odl = ord(l)-97
      
             if odl >=0 and odl <= 25:
                 self.freqL[odl]+=1
             
             odu = ord(l)-65
             if odu >=0 and odu <= 25:
                 self.freqU[odu]+=1

     def DisplayFreq(self, num):

        self.GetFreqSkill(num)

        for i in range(26):
            print(chr(i+ord('a')), end=' ')
        print('\n')
        for f in self.freqL:
            print(f, end=' ')
        print('\n')

        for i in range(26):
            print(chr(i+ord('A')), end=' ')
        print('\n')
        for f in self.freqU:
            print(f, end=' ')
        print('\n')


T=[]

inter = Interview()
inter.Add("C++")
inter.Add("programmation")

inter.DisplayFreq(1)
print(str(inter))

T += [inter]

inter2 = Interview()
inter2.Add("C")
inter2.Add("programmation")
inter2.Add("lead")

T += [inter2]

T.sort(key=lambda i: len(i.skill), reverse=True)

print("FINAL: ----------------------------------------")
for i in T:
    print(str(i), end="\n")

