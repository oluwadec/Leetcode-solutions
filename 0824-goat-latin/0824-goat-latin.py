class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        # Define a set of vowels for O(1) lookups
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        
        # Split the sentence into individual words
        words = sentence.split()
        result = []
        
        for i, word in enumerate(words):
            # Rule 1 & 2: Check if the word starts with a vowel or consonant
            if word[0] in vowels:
                new_word = word + "ma"
            else:
                new_word = word[1:] + word[0] + "ma"
            
            # Rule 3: Append 'a' characters based on the 1-based index (i + 1)
            new_word += "a" * (i + 1)
            
            result.append(new_word)
            
        # Join all processed words back into a single sentence separated by spaces
        return " ".join(result)