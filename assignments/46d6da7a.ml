let a1 = ref [];;
  try
    while true do
      a1 := (read_line ()) :: !a1
    done
  with _ -> begin
    end
  let a21 a19 a2 =
    if List.mem a2 a19
    then a19
    else a2::a19
  let rec a22 a2 a3 a6 = match a6 with
    | [] -> [a2]
    | h::t when a3 = 0 -> a2::t
    | h::t -> h::a22 a2 (a3-1) t;;
  let a4 = List.fold_left a21 [] !a1
  let a4 = List.sort(fun a8 a5 -> compare a8 a5) a4
  let rec a23 a6 = match a6 with
    | [] -> print_string ""
    | head::body ->
       begin
         print_endline head;
         a23 body
       end;;
  let a7 = ref "";;
  let a8 = ref "";;
  let a17 = ref "";;
  let a9 = ref "";;
  let a10 = ref [0];;
  let a11 = ref 0;;
  let a12 = ref 0;;
    a10 := List.tl !a10;
    a1 := List.rev !a1;
    for i=0 to List.length(a4)-1 do
      a7 := List.nth a4 i;
      for j=0 to List.length(!a1)-1 do
        a8 := List.nth !a1 j;
        if ((j mod 2 == 0) && (String.compare !a7 !a8 == 0))
        then a11 := !a11 + 1
        else a11 := !a11;
      done;
      a10 := !a11::!a10;
      a11 := 0;
    done;
    a10 := List.rev !a10;;
    let a13 = ref "";;
    let a14 = ref 0;;
    let a15 = ref 0;;
    let a16 = ref 0;;
    let a17 = ref "";;
    let a18 = ref 0;;
    let a19 = ref [""];;
    let a20 = ref [""];;
      a19 := List.tl !a19;
      a20 := List.tl !a20;
      for i=0 to List.length(a4)-1 do
        a7 := List.nth a4 i;
        if (List.nth !a10 i == 0)
        then a20 := !a7::!a20;
      done;
      while (!a16 < List.length(a4)) do
        while (List.length(!a20) <> 0) do
          a20 := List.sort(fun a8 a5 -> compare a8 a5) !a20;
          a17 := List.nth !a20 0;
          a20 := List.tl !a20;
          a12 := !a12 + 1;
          a19 := !a17::!a19;
          for j=0 to List.length(!a1)-1 do
            a7 := List.nth !a1 j;
            if ((j mod 2 == 1) && (String.compare !a17 !a7 == 0)) then
              begin
                a13 := List.nth !a1 (j-1);
                for k=0 to List.length(a4)-1 do
                  a8 := List.nth a4 k;
                  if (String.compare !a13 !a8 == 0) then
                    begin
                      a14 := ((List.nth !a10 k)-1);
                      a10 := a22 !a14 k !a10;
                      if (!a14 == 0) then
                        begin
                          a20 := !a13::!a20;
                        end;
                    end;
                done;
              end;
          done;
        done;
        a16 := !a16 + 1;
      done;
      if (!a12 <> List.length(a4)) then
        begin
          print_endline "cycle";
        end
      else
        begin
          a19 := List.rev !a19;
          a23 !a19;
        end;
