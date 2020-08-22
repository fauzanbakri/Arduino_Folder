import csv
import pickle
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
from scipy.special import comb

#sesuaikan bagian ini sesuai algoritma yang diinginkan 
from sklearn.neural_network import MLPClassifier
from sklearn.linear_model import LogisticRegression
from sklearn import tree
from sklearn import svm
from sklearn.naive_bayes import GaussianNB
from sklearn.naive_bayes import MultinomialNB
from sklearn.naive_bayes import BernoulliNB
#end of algoritma

#definisikan file yang berisi data
target = '02-data.csv'
pilihan = input("Pilih 1. Data Riil 2. Data Kelas 3. Data Normal: ")
with open(target,'r') as csvFile:
    csvReader = csv.DictReader(csvFile, delimiter=',')
    #csvReader = csv.reader(csvFile, delimiter=',') //this for no header and index row
    X = []
    y = []
    if pilihan == '1': 
        h = 'height'
        w = 'weight'
        s = 'size'
        lbl = "Riil"
    elif pilihan == '2': 
        h = 'cheight'
        w = 'cweight'
        s = 'csize'
        lbl = "Class"
    elif pilihan == '3': 
        h = 'nheight'
        w = 'nweight'
        s = 'nsize'
        lbl = "Rill Normalisasi"
    for row in csvReader:
        tinggi = float(row[h])
        berat = float(row[w])
        size = float(row[s])
        target = float(row['target'])
   
        X.append([tinggi,berat,size])
        y.append(target)
#end of data 
list = []

lrClassifier = LogisticRegression(solver='lbfgs')
lrClassifier.fit(X,y) #harus ada hanya untuk menjalankan predict
#score fit
#print("Score LR:",lrClassifier.score(X,y))

#cross validation
scores_lrClassifier = cross_val_score(lrClassifier, X, y, cv=5, scoring='accuracy')
temp = {"algo":"LR", "mean":scores_lrClassifier.mean(), "max":scores_lrClassifier.max()}
#list.append((temp))


#Run the training and testing based on selected algoritma
# Neural Net
nnClassifier = MLPClassifier(solver='lbfgs', alpha=1e-5, hidden_layer_sizes=(10,10), random_state=1)
scores_nnClassifier = cross_val_score(nnClassifier, X, y, cv=5, scoring='accuracy')

temp = {"algo":"NN","mean":scores_nnClassifier.mean(), "max": scores_nnClassifier.max()}
list.append((temp))


# decision tree fluktuatif
treeClassifier = tree.DecisionTreeClassifier()
scores_treeClassifier = cross_val_score(treeClassifier, X, y, cv=5, scoring='accuracy')
temp = {"algo":"DT", "mean": scores_treeClassifier.mean(), "max": scores_treeClassifier.max()}
#list.append((temp))

# SVM konstan
svmClassifier = svm.SVC(kernel='linear', probability=True, gamma=0.0001)
scores_svmClassifier = cross_val_score(svmClassifier, X, y, cv=5, scoring='accuracy')
temp = {"algo":"SVM", "mean": scores_svmClassifier.mean(), "max": scores_svmClassifier.max()}
#list.append((temp))

# Naive Bayes GNB
klasifikasi_set_gaussNB = GaussianNB()
scores_gaussNB = cross_val_score(klasifikasi_set_gaussNB, X, y, cv=5, scoring='accuracy')
temp = {"algo":"GNB", "mean": scores_gaussNB.mean(), "max": scores_gaussNB.max()}
list.append((temp))

# Naive bayes MNB
klasifikasi_set_mnomialNB = MultinomialNB()
scores_mnomialNB = cross_val_score(klasifikasi_set_mnomialNB, X, y, cv=5, scoring='accuracy')
temp = {"algo":"MNB", "mean":scores_mnomialNB.mean(), "max":scores_mnomialNB.max()}
list.append((temp))

# Naive bayes BNB
klasifikasi_set_bernoulliNB = BernoulliNB()
scores_bernoulliNB = cross_val_score(klasifikasi_set_bernoulliNB, X, y, cv=5, scoring='accuracy')
temp = {"algo":"BNB", "mean":scores_bernoulliNB.mean(), "max":scores_bernoulliNB.max()}
list.append((temp))

#selection sort
s = len(list)
for i in range(s):
	for j in range (i+1,s):
		if(list[i]['mean']>list[j]['mean']):
			temp=list[i]
			list[i]=list[j]
			list[j]=temp

print("Dari data",lbl, s,"Algoritma dari akurasi terkecil hingga terbesar diperoleh:")
for dic in list:
	print(dic['algo'], "\tMean:", dic['mean'], "\tMax:", dic['max'])
	
'''
# save the model to disk
filename = 'finalized_model.sav'
pickle.dump(lrClassifier, open(filename, 'wb'))
# load the model from disk
NNmodel = pickle.load(open(filename, 'rb'))

sex = 'Male'
print ("Input your data: \n")
att = ['Tinggi: ','Berat: ','Ukuran sepatu: ']
new = []
for x in att:
	add = int(input(x))
	new.append(add)
pred = NNmodel.pre([new])
if pred[0] == 0: sex = 'Female'

print ("Result: ", sex)
'''
