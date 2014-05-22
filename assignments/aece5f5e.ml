let a1 = ref [] ;;
let a2 = ref[] ;;
  try
    while true do
      let a3 = input_line stdin in
      a1 := (!a1)@(a3::[]);
    done;
    None
  with
    End_of_file -> None;
  ;;
  module A15 = Map.Make(String);;
  let a4 = ref A15.empty;;
  let rec a10 = function
    | a :: (b :: _ as t) -> if a = b then a10 t else a :: a10 t
    | smaller -> smaller;;
  let a5 = ref false;;
  let a6 = ref 0;;
  let a11 a7 a9=
    a6 := !a6 + 1;
    if ((a9 = a7)&&(((!a6) mod 2)==1)) then (
      a5 := true;
      false;
    )
    else if (((!a6) mod 2)==0)&&(!a5) then (
      a5 := false;
      true;
    )
    else
      (
	a5 := false;
	false;
      )
  ;;
  let a12 a7 =
    a6 := 0;
    a5 := false;
    List.filter (a11 a7) !a1;
  ;;
  let rec a13 a8 =
    let a8 = (List.sort (Pervasives.compare) (a10 a8)) in
    List.iter a14 a8;
  and a14 a9 =
    if not(A15.mem a9 !a4) then (
      a4 := A15.add a9 1 !a4;
      a13 (a12 a9);
      a4 := A15.add a9 2 !a4;
      a2 := (!a2)@(a9::[]);
    )
    else if ((A15.find a9 !a4) == 1) then (
      print_string "cycle\n";
      exit 0;
    )
  ;;
    a13 !a1;
    List.iter ( Printf.printf "%s\n" ) !a2;
  ;;
