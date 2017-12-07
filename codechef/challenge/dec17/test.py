def answer(s):
    a = ""
    for i in s:
        if i <= 'z' and i>='a':
        	i = chr(ord('z') - ord(i) + ord('a'));
        	a = str(a) + str(i)
        else:
        	a = str(a) + str(i)
    return a

s = "wrw blf hvv ozhg mrtsg'h vk"
print answer(s)
s = "Yvzs! I xzm'g yvorvev Lzmxv olhg srh qly zg gsv xlolmb!!"
print answer(s)
