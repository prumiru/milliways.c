// 인터뷰와 추가 정보 입력 함수 (합격 여부 상관없이 모든 후보자에 대해 인터뷰 진행)
void interviewAndFillData() {
    for (int i = 0; i < CANDIDATES; i++) {
        // 기초 정보 복사
        copyString(milliways_arr[i].name, candidates[i].name);

        // 인터뷰로 얻은 정보 (사용자로부터 입력 받기)
        printf("\n[%s] 인터뷰 정보를 입력하세요.\n", candidates[i].name);

        printf("닉네임: ");
        getchar();  // 이전 입력에서 남은 '\n'을 제거
        fgets(milliways_arr[i].nickname, NAME_LEN, stdin);
        milliways_arr[i].nickname[strcspn(milliways_arr[i].nickname, "\n")] = '\0';  // 줄 바꿈 문자 제거

        printf("학력: ");
        fgets(milliways_arr[i].education, NAME_LEN, stdin);
        milliways_arr[i].education[strcspn(milliways_arr[i].education, "\n")] = '\0';  // 줄 바꿈 문자 제거

        printf("키 (m): ");
        scanf_s("%f", &milliways_arr[i].height);

        printf("몸무게 (kg): ");
        scanf_s("%f", &milliways_arr[i].weight);

        printf("혈액형: ");
        getchar();  // \n 처리
        fgets(milliways_arr[i].bloodType, 3, stdin);
        milliways_arr[i].bloodType[strcspn(milliways_arr[i].bloodType, "\n")] = '\0';

        printf("알러지: ");
        fgets(milliways_arr[i].allergy, NAME_LEN, stdin);
        milliways_arr[i].allergy[strcspn(milliways_arr[i].allergy, "\n")] = '\0';

        printf("취미: ");
        fgets(milliways_arr[i].hobby, NAME_LEN, stdin);
        milliways_arr[i].hobby[strcspn(milliways_arr[i].hobby, "\n")] = '\0';

        printf("SNS (예: Instagram - @example): ");
        fgets(milliways_arr[i].sns, NAME_LEN, stdin);
        milliways_arr[i].sns[strcspn(milliways_arr[i].sns, "\n")] = '\0';

        printf("생년월일 (YYYYMMDD): ");
        scanf_s("%d", &milliways_arr[i].birthdate);

        // BMI 카테고리 결정
        determineBMICategory(&milliways_arr[i]);
    }
}

// 밀리웨이즈 멤버 출력 함수 (합격 여부 상관없이 모든 후보자 출력)
void printMilliwaysMembers() {
    printf("\n********** 밀리웨이즈 멤버 리스트 **********\n");
    printf("==============================================\n");
    for (int i = 0; i < CANDIDATES; i++) {
        printf("\n이름: %s\n", milliways_arr[i].name);
        printf("닉네임: %s\n", milliways_arr[i].nickname);
        printf("학력: %s\n", milliways_arr[i].education);
        printf("키: %.2f m\n", milliways_arr[i].height);
        printf("몸무게: %.2f kg\n", milliways_arr[i].weight);
        printf("혈액형: %s\n", milliways_arr[i].bloodType);
        printf("알러지: %s\n", milliways_arr[i].allergy);
        printf("취미: %s\n", milliways_arr[i].hobby);
        printf("SNS: %s\n", milliways_arr[i].sns);
        printf("생년월일: %d\n", milliways_arr[i].birthdate);
        printf("BMI 카테고리: %s\n", milliways_arr[i].bmiCategory);
        printf("----------------------------------------------\n");
    }
}
