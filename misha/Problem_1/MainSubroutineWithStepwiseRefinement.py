def read_input():
    # Read text and keywords from the user
    text = input("Enter the text: ")
    keywords = input("Enter keywords separated by spaces: ").split()
    return text, keywords


def preprocess_text(text):
    # Tokenize text into sentences and words
    sentences = text.split('.')
    tokenized_text = [sentence.strip().split() for sentence in sentences]
    return tokenized_text


def index_keywords(text, keywords):
    keyword_index = {}

    for keyword in keywords:
        keyword_index[keyword] = []
        for i, sentence in enumerate(text):
            for j, word in enumerate(sentence):
                if keyword in word:
                    keyword_index[keyword].append((i, j))

    return keyword_index


def generate_kwic_entries(text, keyword_index):
    kwic_entries = {}

    for keyword, positions in keyword_index.items():
        kwic_entries[keyword] = []
        for i, j in positions:
            start = max(0, j - 3)
            end = min(len(text[i]), j + 4)
            context = ' '.join(text[i][start:end])
            kwic_entries[keyword].append(context)

    return kwic_entries


def display_kwic_entries(kwic_entries):
    for keyword, entries in kwic_entries.items():
        print(f"Keyword: {keyword}")
        for entry in entries:
            print(f"   Context: {entry}")
        print()


def main():
    text, keywords = read_input()
    tokenized_text = preprocess_text(text)
    keyword_index = index_keywords(tokenized_text, keywords)
    kwic_entries = generate_kwic_entries(tokenized_text, keyword_index)
    display_kwic_entries(kwic_entries)


if __name__ == "__main__":
    main()
