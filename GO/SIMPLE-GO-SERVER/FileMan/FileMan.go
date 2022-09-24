package FileMan

import (
	"fmt"
	"os"
)

var BASEPATH = "./FILES/"

func WritetoFile(Date, Message, Identity string) int {

	//create a file
	fileName := Identity + ".txt"
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
	len, err := fo.WriteString("Date : " + Date + "\n" + "Identity : " + Identity + "\n" + "Message: " + "\n" + Message)
	if err != nil {
		panic(err.Error())
	}

	return len

}

func AppendtoFile(Date, Message, Identity string) int {

	//create a file
	fileName := BASEPATH + Identity + ".txt"
	fo, err := os.OpenFile(fileName, os.O_APPEND|os.O_WRONLY|os.O_CREATE, 0600)

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
	len, err := fo.WriteString("Date : " + Date + "\n" + "Identity : " + Identity + "\n" + "Message: " + "\n" + Message)
	if err != nil {
		panic(err.Error())
	}

	return len

}

func ReadFromFile(Identity string) string {
	FileName := Identity + ".txt"
	buf, err := os.ReadFile(BASEPATH + FileName)
	if err != nil {
		panic(err.Error())
	}

	OutString := string(buf)
	return OutString
}
