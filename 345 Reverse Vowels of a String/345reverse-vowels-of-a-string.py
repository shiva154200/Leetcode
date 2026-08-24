class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """

        list1=['a','e','i','o','u','A','E','I','O','U']
        s=list(s)
        
        i=0
        j=len(s)-1

        while(i<=j):
            if(s[i] in list1 and s[j] in list1):
                s[i],s[j]=s[j],s[i]
                i+=1
                j-=1
            if(i>j): break
            if (s[i] not in list1): 
                i+=1
            if(s[j] not in list1):
                j-=1
        return "".join(s)

        