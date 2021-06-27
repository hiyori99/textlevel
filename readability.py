
def main():
    text = input("Text: ")

    letter = count_letter(text)
    words = count_words(text)
    sentence = count_sentence(text)

    # Coleman-Liau指数
    L = int(letter) * 100 / int(words)
    S = int(sentence) * 100 / int(words)
    index = float(0.0588 * L - 0.296 * S - 15.8)

    # 四捨五入
    if index % 1 < 0.55:
        grade = int(index)
    else:
        grade = int(index) + 1

    if index < 1:
        print("Before Grade 1")
    elif 1 <= grade and grade < 17:
        print("Grade {0}" .format(grade))
    else:
        print("Grade 16+")

# 入力されたテキストの文字数を数える
def count_letter(text):
    count = int(len(text))
    # 記号は文字とみなさない
    count -= text.count('-')
    count -= text.count('\'')
    count -= text.count(':')
    count -= text.count(';')
    count -= text.count(',')
    count -= text.count('.')
    count -= text.count('?')
    count -= text.count('!')
    count -= text.count(' ')
    return count

# 入力されたテキストの単語数を数える
def count_words(text):
    count = text.count(' ') + 1
    return count

# 入力されたテキストの文章の数を数える
def count_sentence(text):
    count = text.count('.')
    count += text.count('!')
    count += text.count('?')
    return count

if __name__ == "__main__":
    main()