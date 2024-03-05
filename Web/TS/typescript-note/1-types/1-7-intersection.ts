{
  /**
   * Intersection Types: &
   */
  type Student = {
    name: string;
    score: number;
  };

  type Worker = {
    employeeId: number;
    work: () => void;
  };

  // internWork is Student as well as Worker
  // internWork() can access to both Student and Worker object data
  function internWork(person: Student & Worker) {
    console.log(person.name, person.employeeId, person.work());
  }

  internWork({
    name: 'youngjun',
    score: 1,
    employeeId: 123123,
    work: () => {},
  });
}
