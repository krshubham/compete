def truncate_words(string, truncate_threshold):
  if(truncate_threshold > len(string.split())):
    return(string)
  x = ' '.join(string.split()[:truncate_threshold])
  x += '...'
  return(x)

print(truncate_words("Hello World",4))