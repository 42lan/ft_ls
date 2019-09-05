#!/bin/sh
# chmod 0000 special_file; for h in {0..7}; do for j in {0..7}; do for k in {0..7}; do for l in {0..7}; do chmod $h$j$k$l special_file; diff <(/bin/ls -l special_file) <(./ft_ls -l special_file) || echo "\nchmod" $h$j$k$l; done; done; done; done
touch special_file
chmod 0000 special_file
for h in {0..7};
  do for j in {0..7};
    do for k in {0..7};
      do for l in {0..7};
        do chmod $h$j$k$l special_file;
			/bin/ls -l special_file > a
			./ft_ls -l special_file > b
			diff a b > /dev/null
			if [ $? -gt 0 ]
			then
				echo "chmod" $h$j$k$l
				cat a && cat b
			fi
      done;
    done;
  done;
done
rm -rf special_file a b 
