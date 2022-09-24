package FileMan

import (
	"fmt"
	"math/rand"
	"os"
	"time"
)

var BASEPATH = "./FILES/FLATE-FILES/"

func WritetoFILES(add, pin string) {

	//create a file
	fileName := generateRandomfileName()
	fo, err := os.Create(BASEPATH + fileName)

	//check if file is created sucessfully
	if err != nil {
		fmt.Println("WRITE FAILED")
		panic(err)
	}

	//close file if error
	defer func() {
		if err := fo.Close(); err != nil {
			panic(err)
		}
	}()

	//write to file
	len, err := fo.WriteString("ADD : " + add + "\n" + "PIN : " + pin)
	if err != nil {
		panic(err.Error())
	}
	println(len)

}

func generateRandomfileName() string {
	Pref := "fo_"
	s1 := rand.NewSource(time.Now().UnixNano())
	r1 := rand.New(s1)
	r1string := Pref + fmt.Sprint(r1.Intn(100)) + ".txt"

	return r1string
}
