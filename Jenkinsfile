pipeline {
    agent any

    stages {

        stage('Build') {
            steps {
                echo 'Kompilacja programu C'
                sh 'gcc main.c -o program'
            }
        }

        stage('Run') {
            steps {
                echo 'Uruchamianie programu'
                sh './program'
            }
        }
    }
}
