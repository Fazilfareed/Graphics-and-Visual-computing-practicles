'''rng_object=range(12, 100, 13)
for item in rng_object :
    print(item, end="\t")
    print("Done")
          
print(*rng_object, sep="\t")
print("Done")
word_list = """The rain in spain falls mainly on the plain """.split()
print(f"Word list = {word_list}")
print(*word_list)
for w in word_list :
    print (w)


word = "Flamboyant"
n = len(word)
for i in range (0, n, 2):
    print(word[: : -1] * (i+1))


lst, count, n = [], 0, 5
while count <n:
    x= int(input("Type in an integer:"))
    lst.append(x); count += 1
print(*lst)


numbers = [4,2,7,1,9,5,3]
key=int(input("Enter number to search: "))
index, found= 0, False
while index < len(numbers) and not found:
            if numbers[index] == key:
                found = True
            else:
                index +=1
                \


                  
numbers = [4,2,7,1,9,5,3]
key=int(input("Enter number to search:7"))
index, found = 0, False
while index < len(numbers) and not found:
    if numbers[index] == key:
        found= True
    else:
        index+=1
        
'''

        

def print_pyramid(height, title="*", offset=5) :
    for i in range (height) :
        for j in range(offset + height -i):
            print(" ", end="")
        for k in range (2*i + 1):
            print (title, end= "")
        print()
                
print_pyramid(20)
print_pyramid(5, offset=10)
print_pyramid(5, title= "+")
                



matrix = [ [1,2,3,4], [4,3,2,1], [3,2,1,4] ]
rows = len (matrix)
columns = len (matrix[0])
for i in range(rows):
    for j in range(columns) :
        print(matrix[i][j], end=" ")
        print()



matrix =[["Shangar", "Saleem", "simon", "Saman"],\
         ["Barathy", "Nirthika", "Samantha", "Thaarani"],\
         ["Roy", "Pathma", "Sakeela", "Kamala"]]
rows= len(matrix)
columns = len(matrix[0])
for i in range (rows):
    for j in range (columns) :
        print (f"{matrix[i][j]}", end=" ")
    print()




name_list = ["Mahinthan", "Ramanan", "Mano",\
             "Vinothini", "Saman", "Mathew", "Sureha"]
required_list = [name for name in name_list\
                 if name[0]=='M']
print(required_list)



lst1 = ["Kannan", "Krishnan"]
lst2 = "Jambavathi Kalindi Bathra Bamini".split()
pairs = [ (m,f) for m in lst1 for f in lst2]
for p in pairs:
    print(p)
for i, j in pairs :
    print(f"{i}<-->{j}")
