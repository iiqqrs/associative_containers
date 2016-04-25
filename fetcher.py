import urllib2, re

res=urllib2.urlopen("http://randomtextgenerator.com/")
html=res.read()
rawwords = re.findall('textarea(.*?)/textarea', html.replace('\n',''))[0]
words=re.findall('([a-zA-Z]{1,20})', rawwords)
print words
histo={}
f=file('sets','w')
g=file('results','w')
f.write(words[0])
for word in words[1:]:
    f.write('\n'+word)
    if word in histo:
        histo[word]+=1
    else:
        histo[word]=1
first=True
for key in histo:
    line=key+" "+str(histo[key])
    if first:
        first=False
        g.write(line)
    else:
        g.write('\n'+line)
f.close()
g.close()
