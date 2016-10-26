str1 = 'qwertya2'
srt2 = 'qwertya'

if (str1 == srt2)
	puts 'Строки одинаковые'
else
	i = 0
	while (i <= str1.length - 1) and (i <= srt2.length - 1) and (str1[i] = srt2[i]) 
		i += 1
	end
	printf('Символов совпадает %10d', i)
end
