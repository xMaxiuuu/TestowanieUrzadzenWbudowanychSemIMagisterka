pipeline {
    agent any

    stages {

        stage('Clone') {
            steps {
                echo 'Pobieranie repozytorium'
                git 'https://github.com/TWOJ_LOGIN/jenkins-c-project.git'
            }
        }

        stage('Build') {
            steps {
                echo 'Kompilacja programu C'
                sh 'make'
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
