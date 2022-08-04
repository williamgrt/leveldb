folder="build"

if [ ! -d "$folder" ]
then
  mkdir ${folder}
fi


# shellcheck disable=SC2164
cd $folder
cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .
